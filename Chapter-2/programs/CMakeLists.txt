cmake_minimum_required(VERSION 4.0)
project(Learn-C C)
file(GLOB SRC_FILES *.c)

foreach(src ${SRC_FILES})
    get_filename_component(exec_name ${src} NAME_WE)
    add_executable(${exec_name} ${src})
endforeach()
