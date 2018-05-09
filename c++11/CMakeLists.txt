
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(STATUS "========================")
    message(STATUS "Target compiler is Clang")
    message(STATUS "========================")

    set(CPP11_COMPILER_FLAGS -g -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "========================")
    message(STATUS "Target compiler is GCC")
    message(STATUS "========================")

    set(CPP11_COMPILER_FLAGS -g -std=c++11 -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-unused-variable)
endif()

add_executable (lambdas lambdas.cpp)
target_compile_options(lambdas PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (lambdas_continued lambdas_continued.cpp)
target_compile_options(lambdas_continued PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (uniform_initialization uniform_initialization.cpp)
target_compile_options(uniform_initialization PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (initializer_list initializer_list.cpp)
target_compile_options(initializer_list PRIVATE ${CPP11_COMPILER_FLAGS})