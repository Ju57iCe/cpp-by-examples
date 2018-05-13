#include <iostream>

namespace Units
{

class Distance
{
public:
    //Note the explicit keyword. This enforces strong typing
    //and prevents implicit convertions such as Distance d = 100;
    explicit Distance(double i)
    : m_Meters(i)
    {
    }

    //In order to operate easily with the Distance class we will need
    //to provide the operators needed for the arithmethic operations
    friend Distance operator + (const Distance& a, const Distance& b)
    {
        return Distance(a.m_Meters + b.m_Meters);
    }

    friend Distance operator - (const Distance& a, const Distance& b)
    {
        return Distance(a.m_Meters - b.m_Meters);
    }
	 
    friend Distance operator * (double m, const Distance& a)
    {
        return Distance(m * a.m_Meters);
    }
	  
    friend Distance operator / (const Distance& a, int n)
    {
        return Distance(a.m_Meters / n);
    }
	  
    friend std::ostream& operator<< (std::ostream &out, const Distance& dist)
    {
        out << dist.m_Meters << " m";
        return out;
    }
private:
    //The distance is held in meters.
	double m_Meters;	  
};

Distance operator "" _km(long double d)
{
    return Distance(1000 * d);
}

Distance operator "" _mi(long double c)
{
    return Distance(c * 1600);
}

Distance operator "" _m(long double m)
{
    return Distance(m);
}

Distance operator "" _cm(long double c)
{
    return Distance(c / 100);
}

}

//Note: You can still use the global namespace to declare the operators,
//but it is better not to litter it.
using namespace Units;

int main(int argc, char **argv)
{
    Distance d1 = 1.0_km;
    Distance d2 = 2.0_mi + 5.0_km;
    Distance d3 = 10.0_mi - 1.0_km;
    Distance d4 = 5 * 20.0_cm;

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d4 << std::endl;

    return 0;
}