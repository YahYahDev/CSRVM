---@class std
std = require("lua.Modules.Std.Std")
---@class parse
parse = require("lua.Modules.Parse")


--[[
    Lua C Build System, aka "LCBS" is a automatic build system.

    as long as you follow the following format for your file structure
    the build script will automaticly find and build the source file into
    object files

    project/


        COMMENT:

            the lua directory contains the dependancys for this script and other tooling

        lua/
            Modules/



        COMMENT:

            the build program should automaticly build a folder structure from ./src
            and copy to ./bin if not just copy the same folder/directory structure from ./src

        bin/


        COMMENT:

            Only files in folders in ./src/Modules/ will be compiled
            so just name your module then put the .c files in the named
            directory so they can be compiled

        src/
            Modules/
                example/
                    example.c
                    example.h

        WARNING:
            precompiled librarys are not supported at this moment
            please adjust the final compilation command as needed


            Libs/
                Libexample/
                    example.so or .dll or .a or .lib
                    example.h


            main.c

]]



--Your Target Compiler
local Compiler = "gcc"


--Gets the directorys in ./src/Modules
local CMDModDirs = std.Cmd("ls ./src/Modules")
--Gets the directorys in ./bin/Modules
local CMDBinDirs = std.Cmd("ls ./bin/Modules")

--Parses the raw string from "ls" or what ever command used to list directory
local ModDirs = parse.GetAllBlock(CMDModDirs, "", "\n")


--[[
    if the ./bin/Modules directory doesnt have the same directorys
    then it will build the directory structure from ./src/Modules
]]
if CMDModDirs ~= CMDBinDirs then

    for i = 1, #ModDirs do
        os.execute("mkdir ./bin/Modules/" .. ModDirs[i])
    end

end


--[[
    Stores a tree of key value pair arrays of whats in each ./src/Modules/? directorys


    example:

        ./src/
            Modules/
                random
                    [1]random.c
                    [2]idk.c
                numbers
                    [1]add.c
                    [2]matrix.c
]]
local ModDirSrcs = {}


--[[
    Builds a tree from ModDirs

]]
for i = 1, #ModDirs do

    ModDirSrcs[ModDirs[i]] = parse.GetAllBlock(std.Cmd("ls ./src/Modules/" .. ModDirs[i]), "", ".c\n")

end


--[[
    Runs Compiler to build all the .o files

    Uses the constructed tree to find/build all the source files into .o files to be linked with the main executable

]]
for key in pairs(ModDirSrcs)  do
    print("Compiling Module: ./src/Modules/".. key)

    for i = 1, #ModDirSrcs[key] do
        print("  ".. ModDirSrcs[key][i]..".c")
        os.execute(Compiler .." -c ".."./src/Modules/".. key .."/".. ModDirSrcs[key][i] ..".c -o ./bin/Modules/"..key.."/".. ModDirSrcs[key][i].. ".o")

    end
end


--[[




]]






