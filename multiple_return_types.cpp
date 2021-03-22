#include <iostream>
#include <tuple>
using namespace std;

void Foo(int& out_a , std::string& out_s)
{
    out_a = 7*7 - 44;
    out_s = "return string!";
}

std::tuple<int , std::string> Bar()
{
    return std::tuple<int , std::string> {5 , "return value!"};
}

int main()
{
    //return a string and an int
    //first method: 
    int a;
    std::string s;

    Foo( a, s); // integer a and std::string s will be modified.
    cout << a << endl;
    cout << s << endl;

    // second method of doing is C++17 tuple.
    auto t = Bar();
    cout << std::get<0>(t) << endl;
    cout << std::get<1>(t) << endl;

    // the retrieving method is a little ugly. the preferred way of doing it is whats called structured bindings.
    

    return 0;
}