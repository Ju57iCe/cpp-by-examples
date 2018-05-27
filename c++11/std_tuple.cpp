#include <iostream>
#include <tuple>
#include <string>

int main(int argc, char **argv)
{
    //C++11 itroduces a new type of container - a tuple. The tuple is a
    //heterogeneous, fixed size container, similar to std::pair, but for any,
    //fixed size, number of elements.
    std::tuple<std::string, std::string, float> record {"John Doe", "sample@aol.com", 5.45f};

    //Elements in the tuple can be accessed with std::get<n> with n being the index of the
    //element being accessed. std::get<0> has three overloads that return a reference,
    //a rvalue reference and a const reference.
    std::cout << std::get<0>(record) << " "
                << std::get<1>(record) << " "
                << std::get<2>(record) << std::endl;

    //Elements of the tuple can be edited in two ways:
    std::get<0>(record) = "Redacted";

    auto& mailRef = std::get<1>(record);
    mailRef = "email_deleted";

    std::cout << std::get<0>(record) << " "
                << std::get<1>(record) << " "
                << std::get<2>(record) << std::endl;

    //Tuples can also be created with the std::make_tuple() helper function
    auto simpleTupleOne = std::make_tuple(42, 'b', false);
    auto simpleTupleTwo = std::make_tuple(24, 'd', true);

    //Tuples can be concactenated by using std::tuple_cat
    auto thirdTuple = std::tuple_cat(simpleTupleOne, simpleTupleTwo);

    //The size of a tuple is a constexpr and can be obtained like this:
    size_t totalSize = std::tuple_size<decltype(thirdTuple)>::value;

    std::cout << "thirdTuple contains " << totalSize << " elements: "
                << std::get<0>(thirdTuple) << " "
                << std::get<1>(thirdTuple) << " "
                << std::get<2>(thirdTuple) << " "
                << std::get<3>(thirdTuple) << " "
                << std::get<4>(thirdTuple) << " "
                << std::get<5>(thirdTuple) << " "
                << std::endl;

    std::tuple<int,float,char> anotherTuple;
    anotherTuple = std::make_tuple (99, 3.14, 'c');

    int firstElementValue;
    float secondElementValue;
    //std::tie explodes (or unpacks) tuple elements into varianables. std::ignore
    //can be used to igrore an element for which we don't want to setup a variable
    std::tie (firstElementValue, secondElementValue, std::ignore) = anotherTuple;
    std::cout << "The first element is " << firstElementValue
                << ", the second element is " << secondElementValue
                << std::endl;
}