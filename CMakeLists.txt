cmake_minimum_required(VERSION 3.28)
project(XMOJ)

set(CMAKE_CXX_STANDARD 14)

file(GLOB CPP_FILES "*.cpp")

# Create an executable for each .cpp file
foreach(CPP_FILE ${CPP_FILES})
    get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE)
    add_executable(${EXE_NAME} ${CPP_FILE})
endforeach()