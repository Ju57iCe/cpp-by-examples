#include <iostream>
#include <array>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
    //std::array is a thin wrapper of standard C (fixed size) arrays. It hat the
    //same performance of the C-style arrays, but it also has the benefits of the
    //standard library containers - random access iterator, knowing its own size
    //and compatability with the standard library algorithms. The std::array 
    //however does not decay to T* like the C-style array does.

    //Creates an array of 4 ints and then initializes them.
    std::array<int, 4> intArray { 5, 1, 7, 9};

    //Creates an array of 8 chars and then initializes only the first 3.
    std::array<char, 8> charArray {'a', 'b', 'c'};
    charArray[7] = 'f';

    std::array<std::string, 3> strArray {"Mark", std::string("John"), "Melanie"};

    //Use of std::array with the standard library algorithms
    std::for_each(intArray.begin(), intArray.end(), [](int &n){ std::cout << n << " "; });
    std::cout << std::endl;
    std::sort(intArray.begin(), intArray.end());

    //Support of range based loops
    for (int& i : intArray)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //In case of zero length arrays, array.begin() is the same as array.end() and
    //calling either of them is considered as undefined behavior.
    std::array<float, 0> floatArray;

    //Undefined behavior
    //floatArray.begin();

    return 0;
}