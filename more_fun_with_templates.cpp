#include <iostream>
using namespace std;


// when return type is known..
template <typename T>
int max(T a , T b)
{
    return a > b ? a : b ;
}

// when return type is not known..
// here TR is return type.
template <typename TR , typename T,  typename R> 
TR max(T a, R b)
{
    cout << "return type not known !!" << endl;
    return a>b ? a  : b ;
}


int main()
{
    cout << ::max(44.2 , 233.11124123) << endl;
    cout << ::max<float>(44 , 233.11124123) << endl;

    return -0;
}