cmake_minimum_required(VERSION 3.12)

project(json_geekbench LANGUAGES CXX)

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

add_executable(${PROJECT_NAME}
    Main.cpp
    Bench.h
    Data.cpp Data.h
    JsonForModernCppBench.cpp JsonForModernCppBench.h
    RapidJsonBench.cpp RapidJsonBench.h
    JsonCppBench.cpp JsonCppBench.h
    #rtb/OpenRtb.cpp rtb/OpenRtb.h rtb/Types.h rtb/OpenRtbRef.h rtb/Json.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:
            /MP /W3 /Zf
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
            -Wall -Wextra -Werror -Wpedantic -pedantic-errors -pipe
            -Wno-deprecated-declarations # JsonCpp: 'Reader' is deprecated: Use CharReader and CharReaderBuilder instead
            -Ofast -fomit-frame-pointer -fno-exceptions>
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
)
