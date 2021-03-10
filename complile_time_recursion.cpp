#include <iostream>
using namespace std;

template <int N>
struct Factorial 
{
    static int const value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<1> 
{
    static int const value = 1;
};


int main()
{
    cout << "Factorial 5 : " << Factorial<30>::value << endl;
    return 0;
}