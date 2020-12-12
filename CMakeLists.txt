cmake_minimum_required(VERSION 3.0.0)
project(sfml_app VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if((NOT EXISTS "${CMAKE_SOURCE_DIR}/deps/SFML-2.5.1"))
    # we couldn't find the header files for FOO or they don't exist
    message("Unable to find SFML")
    message("Downloading SFML ...")
    file(DOWNLOAD "https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip" "${CMAKE_SOURCE_DIR}/deps/sfml.zip")
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xzf ${CMAKE_SOURCE_DIR}/deps/sfml.zip
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/deps
    )
else()
    message("SFML is found!")
endif()

add_executable(sfml_app sfml_app.cpp)

add_custom_command(TARGET sfml_app PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/deps/SFML-2.5.1/bin/ ${CMAKE_BINARY_DIR}/bin)

target_include_directories(sfml_app PUBLIC "${CMAKE_SOURCE_DIR}/deps/SFML-2.5.1/include")
target_compile_options(sfml_app PUBLIC "-g")
target_link_directories(sfml_app PUBLIC "${CMAKE_SOURCE_DIR}/deps/SFML-2.5.1/lib")
target_link_libraries(sfml_app PUBLIC "-lsfml-graphics -lsfml-window -lsfml-system")
