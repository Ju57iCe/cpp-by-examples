#include <iostream>
#include <string>
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
        std::cout << std::endl << "The sum of " << a << " and " << b << " is " << sum << std::endl;
        return sum;
    };
    int result = sumFn(1, 2);

    //A lambda function that has no captures and takes two parameters
    //A very good place to use the automatic type deduction of c++11
    auto substractFn = [](int a, int b)
    {  
        int substr = a - b;
        std::cout << std::endl << a << " minus " << b << " equals " << substr << std::endl;
        return a - b;
    };
    int subRes = substractFn(10, 3);


    int bananas = 5;
    std::cout << std::endl << "Bananas before addToFruitFn is called - " << bananas << std::endl;

    //A lambda fn that captures bananas variable by reference and then increments it.
    auto addToFruitFn = [&bananas]()
    {
        bananas++;
    };

    addToFruitFn();
    std::cout << "Bananas after addToFruitFn is called - " << bananas << std::endl;


    std::string str("foo");

    //A lambda that captures str by copy and takes a string as a parameter
    auto printWithSuffix = [str](std::string suffix)
    {
        std::cout << "Printing with suffix - " << str+suffix << std::endl;
    };
    printWithSuffix("bar");


    //A lambda that captures all auto variables (local to the current scope) by reference
    auto changeLocalVars = [&]()
    {
        result = result * result;
        subRes++;
        bananas += 2;
        str = "foo foo bar";
    };
    changeLocalVars();
    std::cout << std::endl
                << "Result is now: " << result << std::endl
                << "subRes is now: " << subRes << std::endl
                << "Bananas are now: " << bananas << std::endl
                << "str is now: " << str << std::endl
                << std::endl;

    //A lambda that captures all auto variables (local to the current scope) by value
    auto printLocalVars = [=]()
    {
        std::cout << std::endl
                << "Result is still: " << result << std::endl
                << "subRes is still: " << subRes << std::endl
                << "Bananas are still: " << bananas << std::endl
                << "str is still: " << str << std::endl
                << std::endl;
    };
    printLocalVars();

    return 0;
}