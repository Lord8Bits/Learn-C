file(GLOB SRC_FILES *.c)

foreach(src ${SRC_FILES})
    get_filename_component(exec_name ${src} NAME_WE)
    add_executable(${exec_name} ${src})
endforeach()
