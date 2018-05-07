set(CPP11_COMPILER_FLAGS "-g -std=c++11 -Wall -Wextra")

add_executable (lambdas lambdas.cpp)
target_compile_options(lambdas PRIVATE ${CPP11_COMPILER_FLAGS0})

add_executable (lambdas_continued lambdas_continued.cpp)
target_compile_options(lambdas_continued PRIVATE ${CPP11_COMPILER_FLAGS0})

add_executable (uniform_initialization uniform_initialization.cpp)
target_compile_options(uniform_initialization PRIVATE ${CPP11_COMPILER_FLAGS0})