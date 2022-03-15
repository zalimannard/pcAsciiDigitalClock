cmake_minimum_required(VERSION 2.8)

project(pctime)

set(SOURCE main.cpp 
    AsciiChar.cpp
    AsciiStorage.cpp
    AsciiString.cpp
    )
set(HEADER 
    AsciiChar.h
    AsciiStorage.h
    AsciiString.h
    )

add_executable(pctime ${SOURCE})
