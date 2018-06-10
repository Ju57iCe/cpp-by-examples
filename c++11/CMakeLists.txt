
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CPP11_COMPILER_FLAGS -g -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
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

add_executable (user_defined_literals user_defined_literals.cpp)
target_compile_options(user_defined_literals PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (default_deleted_functions default_deleted_functions.cpp)
target_compile_options(default_deleted_functions PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (delegated_constructors delegated_constructors.cpp)
target_compile_options(delegated_constructors PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (std_array std_array.cpp)
target_compile_options(std_array PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (std_tuple std_tuple.cpp)
target_compile_options(std_tuple PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (range_based_loops range_based_loops.cpp)
target_compile_options(range_based_loops PRIVATE ${CPP11_COMPILER_FLAGS})

add_executable (fixed_witdth_integers fixed_witdth_integers.cpp)
target_compile_options(fixed_witdth_integers PRIVATE ${CPP11_COMPILER_FLAGS})