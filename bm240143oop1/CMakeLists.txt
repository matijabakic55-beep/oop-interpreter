cmake_minimum_required(VERSION 4.0)
project(untitled64)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled64 main.cpp
        Reader.h
        Reader.cpp
        Parser.h
        Parser.cpp
        Interpreter.h
        Interpreter.cpp
        Commands.h
        Commands.cpp
        CommandCreator.h
        CommandCreator.cpp
        Time.h
        Time.cpp
        Date.h
        Date.cpp
        Echo.h
        Echo.cpp
        Prompt.h
        Prompt.cpp
        Touch.h
        Touch.cpp
        Truncate.h
        Truncate.cpp
        Rm.h
        Rm.cpp
        Wc.h
        Wc.cpp
        Head.h
        Head.cpp
        Tr.h
        Tr.cpp
        Batch.h
        Batch.cpp
        Exec.h
        Exec.cpp)
