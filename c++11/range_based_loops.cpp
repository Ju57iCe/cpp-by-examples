#include <iostream>
#include <string>
#include <map>
#include <vector>

int main(int argc, char **argv)
{
    std::map<std::string, float> scoresMap { {"John", 4.4f},
                                                {"Mark", 6.0f},
                                                {"Paul", 3.2f},
                                                {"Kate", 5.2f},
                                            };
    //A range based for loop capturing a map element as a const reference
    for (const auto& entry : scoresMap )
    {
        std::cout << entry.first << " has a mark of " << entry.second << std::endl;
    }

    std::vector<int> intVector {1, 2, 3, 4, 5};
    //A range based for loop capturing a element by reference
    for (auto& element : intVector)
    {
        element += 2;
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> strVector {"one", "two", "three", "four", "five"};
    //A range based for loop capturing a element by value
    for (auto element : strVector)
    {
        const char randOne = 65 + rand() % 57;
        element.append(1, randOne);

        const char randTwo = 65 + rand() % 57;
        element.append(1, randTwo);

        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "The contents in the array after the appends are: ";
    for (auto& element : strVector) { std::cout << element << " "; }
    std::cout << std::endl;

    //ToDo - example of class supporting range based for loops

    return 0;
}