#include <iostream>
#include <vector>

struct FloatStorage
{
public:
    FloatStorage(float a, float b, float c)
    {
        m_Storage.push_back(a);
        m_Storage.push_back(b);
        m_Storage.push_back(c);
    }

    //User defined constructor with initializer list
    FloatStorage(std::initializer_list<double> listParams)
    {
        for(auto it = listParams.begin(); it != listParams.end(); it++)
        {
            m_Storage.push_back(*it);
        }
    }

    //It is possible to have more than one constructor with initializer list
    FloatStorage(std::initializer_list<FloatStorage> list)
    { 
        std::cout << "Using initializer list c-tor" << std::endl;
        if (list.size() > 0)
        {
            m_Storage = list.begin()->m_Storage;
        }
    }

    void PrintStorage()
    {
        std::cout << "The storage has: ";
        for (float i : m_Storage)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
private:
    std::vector<float> m_Storage;
};


int main(int argc, char **argv)
{
    //Using normal constructor
    FloatStorage s1(1.1, 4.5, 19.3);
    s1.PrintStorage();

    //Using initializer list constructor
    FloatStorage s2 {3.14, 42.5, 39.4};
    s2.PrintStorage();

    //Constructing s3 from s2 using an initializer list
    FloatStorage s3 {s2};

    return 0;
}