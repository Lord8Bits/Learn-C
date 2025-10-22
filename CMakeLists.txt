cmake_minimum_required(VERSION 3.10)
project(Learn_C C)

# Search all chapter directories
file(GLOB CHAPTER_DIRS RELATIVE ${CMAKE_SOURCE_DIR} Chapter-*)

foreach(chapter ${CHAPTER_DIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${chapter})
        add_subdirectory(${chapter})
    endif()
endforeach()