class CantCopyMe
{
public:
    //Explicitly telling the compiler to declare and define a default constructor
    CantCopyMe() = default;

    //Explicitly prevents the compiler from generating
    //copy constructor and an assignment operator
    CantCopyMe(const CantCopyMe&) = delete;
    CantCopyMe& operator=(const CantCopyMe&) = delete; 

    ~CantCopyMe();

    void AddToData(int a) { m_Data += a; }

    //Delete overloads of addtodata with float or double.
    //It is a way to enforce strong typizatition and prevent implicit convertions.
    void AddToData(float a) = delete;
    void AddToData(double a) = delete;
private:
    int m_Data;
};

//Any special member function - default constructor, copy/move constructor,
//copy/move assignment operator and destructor, can be declared default outside the class
CantCopyMe::~CantCopyMe() = default;


//Another way to enforce strong typization is to combine a templates with
//deleted functions. This is dony by delcaring myFn(T) deleted, and then
//explicitly declaring the allowed usage of myFn with double .
template < typename T >  
void myFn(T) =delete;  
void myFn(double param) { return; } 


int main(int argc, char **argv)
{
    CantCopyMe instanceA;
    CantCopyMe instanceB;

    //Uncommenting these lines will result in error: use of deleted function
    //instanceA = instanceB;
    //CantCopyMe instanceC(instanceB);

    //Trying to used add to data with float or double will result in error
    //instanceB.AddToData(2.f);
    //instanceB.AddToData(2.0);

    myFn(3.0);
    //myFn(2.f);

    return 0;
}