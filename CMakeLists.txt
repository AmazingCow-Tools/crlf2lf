##~---------------------------------------------------------------------------##
##                     _______  _______  _______  _     _                     ##
##                    |   _   ||       ||       || | _ | |                    ##
##                    |  |_|  ||       ||   _   || || || |                    ##
##                    |       ||       ||  | |  ||       |                    ##
##                    |       ||      _||  |_|  ||       |                    ##
##                    |   _   ||     |_ |       ||   _   |                    ##
##                    |__| |__||_______||_______||__| |__|                    ##
##                             www.amazingcow.com                             ##
##  File      : CMakeLists.txt                                                ##
##  Project   : crlr2lf                                                       ##
##  Date      : Feb 19, 2018                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : n2omatt <n2omatt@amazingcow.com>                              ##
##  Copyright : AmazingCow - 2018                                             ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##

cmake_minimum_required(VERSION 3.5)

##----------------------------------------------------------------------------##
## Project                                                                    ##
##----------------------------------------------------------------------------##
set(PROJECT crlf2lf)
set(CMAKE_CXX_STANDARD 11)

project(${PROJECT})


##----------------------------------------------------------------------------##
## Sources                                                                    ##
##----------------------------------------------------------------------------##
set(SOURCES 
    src/main.cpp
)

##----------------------------------------------------------------------------##
## Libraries                                                                  ##
##----------------------------------------------------------------------------##
add_subdirectory(libs/acow_c_goodies    )
add_subdirectory(libs/acow_cpp_goodies  )
add_subdirectory(libs/acow_posix_goodies)
add_subdirectory(libs/CoreAssert        )
add_subdirectory(libs/CoreFile          )
add_subdirectory(libs/CoreFS            )
add_subdirectory(libs/CoreLog           )
add_subdirectory(libs/CoreString        )
add_subdirectory(libs/libtermcolor      )


##----------------------------------------------------------------------------##
## Executable                                                                 ##
##----------------------------------------------------------------------------##
##------------------------------------------------------------------------------
## Executable.
add_executable(${PROJECT} ${SOURCES})

##------------------------------------------------------------------------------
## Dependencies
target_link_libraries(crlf2lf LINK_PUBLIC acow_c_goodies    )
target_link_libraries(crlf2lf LINK_PUBLIC acow_cpp_goodies  )
target_link_libraries(crlf2lf LINK_PUBLIC acow_posix_goodies)
target_link_libraries(crlf2lf LINK_PUBLIC CoreAssert        )
target_link_libraries(crlf2lf LINK_PUBLIC CoreFile          )
target_link_libraries(crlf2lf LINK_PUBLIC CoreFS            )
target_link_libraries(crlf2lf LINK_PUBLIC CoreLog           )
target_link_libraries(crlf2lf LINK_PUBLIC CoreString        )
target_link_libraries(crlf2lf LINK_PUBLIC libtermcolor      )

install(TARGETS ${PROJECT} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})