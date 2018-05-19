#include <iostream>

class IntStorage
{
public:
    IntStorage(int a)
    {
        m_A = a > 0 ? a : -1;
    }

    IntStorage(int a, int b)
    : IntStorage(a)
    {
        m_B = b > 0 ? b : -1;
    }

    //Note: When using a delegated constructor, the member initializer list is
    //forbidden. Using an initializer list after a delegated constructor will
    //result in a compililation error.

    // IntStorage(int a, int b)
    // : IntStorage(a)
    // , m_B(-1)
    // {
    // }

    IntStorage(int a, int b, int c)
    : IntStorage(a, b)
    {
        m_C = c > 0 ? c : -1;
    }

    void PrintValues()
    {
        std::cout << "The values are A: " << m_A
                    << ", B: " << m_B
                    << ", C: " << m_C << std::endl;
    }

private:
    int m_A;
    int m_B;
    int m_C;
};

//Be careful when using delegated constructors not to cause infinite recursion.
//The following example will demonstrate running out of stack memory due to
//infinite recursion.
class BadExample
{
public:
    // don't do this
    BadExample()
    : BadExample('a', 'b')
    {
    }

    BadExample(int my_max, int my_min)
    : BadExample()
    {
    }
private:
    char m_A;
    char m_B;
};
//ToDo - demonstrate constructor recursion

int main(int argc, char **argv)
{
    IntStorage myStorage{ 1, -231, 2 };
    myStorage.PrintValues();

    //BadExample doNotDoThis('f', 'l');
}

