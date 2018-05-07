#include <iostream>
#include <functional>
class Triangle
{
public:
    Triangle()
    : m_A(0)
    , m_B(0)
    , m_C(0)
    {
        //A lambda that captures this pointer and then prints the
        //member variables of class Triangle
        printFn = [this](){
            std::cout << "The sides of triangle " 
                        << this
                        << " are now: "
                        << m_A << ", "  //Note the implicit context of this
                        << m_B << ", "
                        << this->m_C    //Although, you can still use explicitly this
                        << std::endl;
        };
    }

    void SetSides(int a, int b, int c)
    {
        m_A = a;
        m_B = b;
        m_C = c;
        printFn();
    }

private:
    std::function<void()> printFn;
private:
    int m_A;
    int m_B;
    int m_C;

};

int main(int argc, char **argv)
{
    Triangle t;
    t.SetSides(4, 8, 9);
    t.SetSides(8, 13, 4);

    int Num = 5;
    std::cout << std::endl << "Num is " << Num << std::endl;
    //A lambda function that captures "Num" by value and then changes the copy of "Num"
    //into its scope. Note that without the mutable attribute this is not possible as
    //the compiler marks the varible captured by value as a const.
    auto incrementfn = [Num]() mutable {
        Num++;
        std::cout << "Num in the lambda is " << Num << std::endl;
    };
    incrementfn();
    std::cout << "Num is " << Num << std::endl << std::endl;

    //Lambdas can also have noexcept attribute, declaring that the lambda, or a
    //function called by the lambda will not throw.
    auto printFn = [Num]() noexcept {
        std::cout << "No-except print - " << Num << std::endl;
    };
    printFn();

    return 0;
}