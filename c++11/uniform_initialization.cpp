#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <string>
#include <utility>

class A
{
    A(int x, int y, int z)
    : m_MemberArray{x, y, z} // Uniform initialization of member variable
    {
    };

    std::pair<int, std::string> GetAPair()
    {
        return {42, "fourty-two"}; //Uniform unitialization of a returned object
    }

public:
    int m_MemberArray[3];
};

void printPair(std::pair<std::string, double> p)
{
    std::cout << "The pair contains " << p.first << " and " << p.second << std::endl;
}

int main(int argc, char **argv)
{
    int intArray[5] {0, 1, 2, 3, 4};

    int* dynArray = new int[5] {1, 2, 3, 4, 5};
    delete [] dynArray;

    std::array<int, 5> stdIntArray {0, 1, 2, 3, 4};

    //Uniform initialization of multiple pairs of int and string
    std::map <int, std::string> intToStrMap { {1, "One"},
                                                {2, "Two"},
                                                {3, "Three"},
                                                {4, "Four"},
                                                {5, "Five"}
                                            };

    std::vector<double> doubles {0.0, 1.0, 2.0, 3.0, 4.0,};

    //Constructing a pair that will be passed to the function
    printPair({"fourty_two", 42});

    //Note: Type narrowing in uniform initialization is forbidden.
    //Uncommenting this expression will raise an error.
    //int myInt{42.0};

    //Todos
    //example of initializer list/uniform initialization in user defined type
    //type narrowing is forbidden when using uniform initialization
    //check delegating constructors overlap

    return 0;
}