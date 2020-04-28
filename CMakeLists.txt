cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project ("file-bomb")

### CXX Compilier
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (main "main.cpp")
