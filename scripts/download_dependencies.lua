#!/usr/env lua

local PATH = require("PATH");
local lfs  = require("lfs" );

function get_script_fullpath()
    local str = debug.getinfo(2, "S").source:sub(2)
    return str;
 end


local script_fullpath = get_script_fullpath();
local script_dir      = PATH.dirname(script_fullpath);
local target_dir      = PATH.join(script_dir, "../libs");

local repos_to_clone = table.concat({
    "AmazingCow-Libs/acow_c_goodies",
    "AmazingCow-Libs/acow_cpp_goodies",
    "AmazingCow-Libs/acow_posix_goodies",
    "AmazingCow-Libs/CoreAssert",      
    "AmazingCow-Libs/CoreFile",        
    "AmazingCow-Libs/CoreFS",          
    "AmazingCow-Libs/CoreLog",         
    "AmazingCow-Libs/CoreString",      
    "AmazingCow-Libs/libtermcolor"    
}, " ");

os.execute(string.format(
    "github-clone.lua %s %s", 
    target_dir,
    repos_to_clone
));