#include <iostream>
#include <memory>
#include <string>

class Table
{
    public:
    Table()
    : m_RowOne("Row one is empty.")
    , m_RowTwo("Row two is empty.")
    {
    }

    ~Table()
    {
    }

    void PrintContents()
    {
        std::cout << m_RowOne << std::endl << m_RowTwo << std::endl;
    }

    std::string GetRowOne() { return m_RowOne; }
    void SetRowOne(std::string rOne) { m_RowOne = rOne; }

    std::string GetRowTwo() { return m_RowTwo; }
    void SetRowTwo(std::string rTwo) { m_RowTwo = rTwo; }

    private:
    std::string m_RowOne;
    std::string m_RowTwo;
};


int main(int argc, char** argv)
{
    // C++11 introduces three new types of smart pointers and deprecates the
    // use of auto_ptr. The three new types are:

    // std::unique_ptr - holds the ownership of a raw pointer, while
    // providing direct access to it. Releases the memory when it goes out of scope.
    // std::unique_ptr

    // Initialization of unique_ptr using its constructor
    std::unique_ptr<Table> t1(new Table()); // Note: make_unique is not available in c++11

    // Initialization of unique_ptr using rvalue
    std::unique_ptr<Table> tOne = std::unique_ptr<Table>(new Table());

    // Initialization of unique_ptr holding an array of 2 Tables
    std::unique_ptr<Table[]> tableArray(new Table[2]());

    // Assigning an unique_ptr to existing unique_ptr is forbidden. And will generate a
    // compiler error. 
    //std::unique_ptr<Table> t2 = t1;

    // However, if we want to transfer the ownerhip of the pointer from t1 to t2,
    // we can do so, by moving them.

    // Note: after the move, you shouldn't use t1 anymore.
    std::unique_ptr<Table> t2 = std::move(t1);

    // If we want to forcefully lose ownership of the pointer being managed,
    // we can call Release();
    Table* unManagedPtr = tableArray.release();
    delete[] unManagedPtr;

    // Another way to initialize an unique_ptr is to use the reset() method.
    // The reset() howeverhas a distinct behavior, depending on the state of
    //the unique_ptr.

    //Declaring an empty unique_ptr
    std::unique_ptr<Table> t3;

    //t3 takes the ownership of the newly allocated table
    t3.reset(new Table);

    // unique_ptr has an overloaded arrow operator, so you can call the pointer
    // methods as you would with normal pointer.
    t3->SetRowOne("John");

    std::cout << "t3's row one is: " << t3->GetRowOne() << std::endl;

    // Since t3 already has an object that it manages, the next time the reset is called,
    // it will delete the managed object, which in turn will call the destructor
    // of the managed object. Then it will create a new managed object that will be tracked.
    t3.reset(new Table);
    
    std::cout << "t3's row one is: " << t3->GetRowOne() << std::endl;

    // Calling the reset method with no pointer will simply delete the managed object.
    t3.reset();

    // unique_ptr has an operator bool overloaded, which indicates whether the unique_ptr
    // currently holds a managed object.
    if (!t3)
    {
        std::cout << "t3 is empty" << std::endl;
    }

    // Note, when an unique_ptr goes out of scope, it will automatically delete
    // the managed object it is holding.
    auto tempTable = std::unique_ptr<Table>(new Table());

    return 0;
}