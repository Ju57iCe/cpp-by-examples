add_executable (lambdas lambdas.cpp)
target_compile_options(lambdas PRIVATE -std=c++11 -Wall -Wextra)

add_executable (lambdas-continued lambdas-continued.cpp)
target_compile_options(lambdas-continued PRIVATE -std=c++11 -Wall -Wextra)