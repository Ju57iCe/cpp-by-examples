#include <iostream>
#include <memory>
#include <string>

class Table
{
    public:
    Table() : m_RowOne("Row one is empty."), m_RowTwo("Row two is empty.")
    {
        std::cout << "Constructing table" << std::endl;
    }

    ~Table()
    {
        std::cout << "Destructing table" << std::endl;
    }

    void PrintContents()
    {
        std::cout << m_RowOne << std::endl << m_RowTwo << std::endl;
    }

    private:
    std::string m_RowOne;
    std::string m_RowTwo;
};


int main(int argc, char** argv)
{
    // std::shared_ptr - a smart pointer that holds a reference count to the
    // shared memory and automatically releases the shared memory (calls the destructor)
    // of the class when the reference counter reaches zero.
    // shared_ptr

    // std::weak_ptr - a weak pointer is created from a shared pointer and can be used
    // for observing the raw pointer. Weak pointers do not increase the reference count
    // of the shared pointer and can be used when you want to use the shared object, but
    // do not want to take ownership of the shared object.
}