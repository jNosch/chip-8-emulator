cmake_minimum_required(VERSION 3.26)

project(Chi_8_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


list(APPEND CMAKE_PREFIX_PATH "C:/Users/RageZ/Documents/Personal Projects/Emulating/SDL3-3.2.16/x86_64-w64-mingw32/lib/cmake/SDL3")

find_package(SDL3 REQUIRED)

add_executable(Chi_8_project main.cpp
        src/hardware/chip8Core.cpp
        src/opcode/instructions.cpp
        src/opcode/instructions.h
        src/hardware/chip8Core.h
        src/opcode/opcodeTable.cpp
        src/opcode/opcodeTable.h
        src/mainCycle/chip8Emulator.cpp
)


target_link_libraries(Chi_8_project SDL3::SDL3)
target_include_directories(Chi_8_project PRIVATE SDL3::SDL3)