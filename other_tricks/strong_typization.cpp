//This example will demonstrate strong type typization by using
//a combination of templates and phantom types or phantom tags.

template <typename T, typename phantomType>
struct StrongType
{
public:
    StrongType (T val)
    : m_Value(val)
    {
    }
private:
    T m_Value;
};

//Declare the types that we nant to strongly type
struct TemberatureInCelsius{};
struct TemperatureInFahrenheit{};

//Typedef the strong types because of the long and ugly name
typedef StrongType<float, TemberatureInCelsius> TCelsius;
typedef StrongType<float, TemperatureInFahrenheit> TFahrenheit;

//A couple of sample functions to demonstrate the strong typization
TCelsius GetTCelsius()
{
    TCelsius ret(24.0f);
    return ret;
}

TFahrenheit GetTFahrenheit()
{
    TFahrenheit ret(200.0f);
    return ret;
}

void SetTFahrenheit(TFahrenheit t)
{
}

void SetTCelsius(TCelsius t)
{
}

//Another way to enforce strong typization is to combine a templates with
//deleted functions. This is dony by delcaring myFn(T) deleted, and then
//explicitly declaring the allowed usage of myFn with double .
template < typename T >
void myFn(T) = delete;
void myFn(double param) { return; }

int main(int argc, char **argv)
{
    TCelsius t1 = GetTCelsius();
    SetTCelsius(t1);

    TFahrenheit t2 = GetTFahrenheit();

    //Attempting to convert from TFahrenheit to TCelsius will result in
    //compiler error
    //SetTCelsius(t2);

    //Attempting to get a sum of temperatures will result in compiler error
    //saying there is no operator + (as expected)
    //t1 = t1 + t2;

    return 0;
}