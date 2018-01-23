cmake_minimum_required(VERSION 3.7)
project(crlf2lf)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    ./libs/CoreAssert
    ./libs/CoreFile
    ./libs/CoreFS
    ./libs/CoreLog
    ./libs/CoreString
    ./libs/libtermcolor
	./libs/acow_nt_posix
	./libs/acow_cpp_goodies
)

add_executable(crlf2lf
    ./libs/CoreAssert/CoreAssert/src/private/PrivateHelpers.cpp

    ./libs/CoreFile/CoreFile/src/CoreFile.cpp

    ./libs/CoreFS/CoreFS/src/CoreFS.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS_Unix.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS_Win32.cpp

    ./libs/CoreLog/CoreLog/src/Log.cpp
    ./libs/CoreLog/CoreLog/src/Logger.cpp
    ./libs/CoreLog/CoreLog/src/private/os_functions.cpp

    ./libs/CoreString/CoreString/libs/asprintf/asprintf.cpp
    ./libs/CoreString/CoreString/libs/asprintf/vasprintf-c99.cpp
    ./libs/CoreString/CoreString/src/CoreString.cpp

    ./libs/libtermcolor/termcolor/src/Config.cpp
    ./libs/libtermcolor/termcolor/src/Functions.cpp

    ./src/main.cpp
)
