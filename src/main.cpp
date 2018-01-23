// std
#include <vector>
#include <string>
// Amazing Cow Libs
#include "CoreAssert/CoreAssert.h"
#include "CoreFS/CoreFS.h"
#include "CoreFile/CoreFile.h"
#include "CoreLog/CoreLog.h"
#include "CoreString/CoreString.h"


//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define PROGRAM_NAME "clrf2lf"

#define COW_CLRF2LF_VERSION_MAJOR    "0"
#define COW_CLRF2LF_VERSION_MINOR    "1"
#define COW_CLRF2LF_VERSION_REVISION "0"

#define COW_CLRF2LF_VERSION           \
        COW_CLRF2LF_VERSION_MAJOR "." \
        COW_CLRF2LF_VERSION_MINOR "." \
        COW_CLRF2LF_VERSION_REVISION


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
void show_help(int exitCode = 0) noexcept
{
    auto msg = R"(usage:
    %s <filename>)";

    printf("%s\n", CoreString::Format(msg, PROGRAM_NAME).c_str());
    exit(exitCode);
}

//------------------------------------------------------------------------------
// File management.
const std::string read_contents(const std::string &filename) noexcept
{
    auto abs_path = CoreFS::AbsPath(filename);
    return CoreFile::ReadAllText(abs_path);
}

void write_contents(
    const std::string &filename,
    const std::string &contents) noexcept
{
    //--------------------------------------------------------------------------
    // Need convert to raw bytes since the text writing will convert back
    // the \n to \r\n.
    auto bytes = std::vector<CoreFile::byte_t>(
        std::begin(contents),
        std::end  (contents)
    );
    CoreFile::WriteAllBytes(filename, bytes);
}

//------------------------------------------------------------------------------
// Contents management.
bool check(const std::string &contents) noexcept
{
    return CoreString::Contains(contents, "\r\n", false);
}

void convert(const std::string &filename) noexcept
{
    auto contents = read_contents(filename);
    if(!check(contents))
        return;

    // COWTODO(n2omatt): Should we write atomically?
    auto replaced = CoreString::Replace(contents, "\r\n", "\n");
    write_contents(filename, replaced);
}


//----------------------------------------------------------------------------//
// Entry Point                                                                //
//----------------------------------------------------------------------------//
int main(int argc, char *argv[])
{
    //--------------------------------------------------------------------------
    // User didn't passed any filenames.
    if(argc == 1)
        show_help(1);

    //--------------------------------------------------------------------------
    // Check if all filenames are valid.
    auto filenames = std::vector<std::string>();
    filenames.reserve(argc-1);

    for(int i = 1; i < argc; ++i)
    {
        if(!CoreFS::IsFile(argv[i]))
            CoreLog::Fatal("Filename doesn't exists - (%s)", argv[i]);

        filenames.push_back(argv[i]);
    }

    //--------------------------------------------------------------------------
    // Convert.
    for(const auto &filename : filenames)
        convert(filename);
}