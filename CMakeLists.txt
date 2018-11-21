cmake_minimum_required(VERSION 3.12)

project(json_geekbench)

# Extend a list of directories specifying a search path for CMake modules
# to be loaded by the the include() or find_package() commands.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(conan)
conan_cmake_run(CONANFILE conanfile.txt
    BASIC_SETUP CMAKE_TARGETS
    BUILD_TYPE "Release"
    BUILD missing
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    Main.cpp
    Bench.h
    Data.cpp Data.h
    JsonForModernCppBench.cpp JsonForModernCppBench.h
    RapidJsonBench.cpp RapidJsonBench.h
    JsonCppBench.cpp JsonCppBench.h)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
)
