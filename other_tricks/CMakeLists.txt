if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CPP11_COMPILER_FLAGS -g -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CPP11_COMPILER_FLAGS -g -std=c++11 -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-unused-variable)
endif()

add_executable (strong_typization strong_typization.cpp)
target_compile_options(strong_typization PRIVATE ${CPP11_COMPILER_FLAGS})