#include <iostream>
#include <array>
#include <vector>
#include <map>

int main(int argc, char **argv)
{
    int intArray[5] {0, 1, 2, 3, 4};

    std::array<int, 5> stdIntArray {0, 1, 2, 3, 4};

    std::map <int, std::string> intToStrMap { {1, "One"},
                                                {2, "Two"},
                                                {3, "Three"},
                                                {4, "Four"},
                                                {5, "Five"}
                                            };

    std::vector<double> doubles {0.0, 1.0, 2.0, 3.0 ,4.0,};

    //Todos
    //example of initializer list/uniform initialization in user defined type
    //type narrowing is forbidden when using uniform initialization
}