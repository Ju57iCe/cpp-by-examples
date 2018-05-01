#include <iostream>
#include <functional>

int main(int argc, char **argv)
{
    //std function from <functional>
    //                                |--- Captures - capture parameters that can be used in the lambda function body (none in this example) 
    //                                |  -- Lambda function parameters
    //                                |  |
    std::function<void()> simpleFn = []  ()                 //|
    {                                                       //| Function 
        std::cout << "Simple function called" << std::endl; //| body
    };                                                      //|
    simpleFn();

    //Lambda function that has no captures and takes two ints as input parameters
    std::function<int(int, int)> sumFn = [](int a, int b)
    {  
        int sum = a + b;
        std::cout << sum << std::endl;
        return sum;
    };
    int result = sumFn(1, 2);

    //A very good place to use the automatic type deduction of c++11
    auto substractFn = [](int a, int b)
    {  
        return a - b;
    };

    //Todo: [a, &b] capture by value and capture by reference
    // [this] capture this
    // capture [&] capture all auto variables by reference
    // capture [=] capture all auto variables by copy 
}