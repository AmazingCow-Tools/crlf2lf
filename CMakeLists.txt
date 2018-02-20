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

##------------------------------------------------------------------------------
## Project Settings.
project(crlf2lf)
set(CMAKE_CXX_STANDARD 11)

##------------------------------------------------------------------------------
## Sources.
add_executable(crlf2lf
     ./src/main.cpp
)


##------------------------------------------------------------------------------
## Libs.
add_subdirectory(libs/acow_cpp_goodies)
add_subdirectory(libs/acow_nt_posix   )
add_subdirectory(libs/CoreAssert      )
add_subdirectory(libs/CoreFile        )
add_subdirectory(libs/CoreFS          )
add_subdirectory(libs/CoreLog         )
add_subdirectory(libs/CoreString      )
add_subdirectory(libs/libtermcolor    )


target_link_libraries(crlf2lf LINK_PUBLIC acow_cpp_goodies)
target_link_libraries(crlf2lf LINK_PUBLIC acow_nt_posix   )
target_link_libraries(crlf2lf LINK_PUBLIC CoreAssert      )
target_link_libraries(crlf2lf LINK_PUBLIC CoreFile        )
target_link_libraries(crlf2lf LINK_PUBLIC CoreFS          )
target_link_libraries(crlf2lf LINK_PUBLIC CoreLog         )
target_link_libraries(crlf2lf LINK_PUBLIC CoreString      )
target_link_libraries(crlf2lf LINK_PUBLIC libtermcolor    )