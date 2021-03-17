#include <iostream>
#include <random>
using namespace std;

template <typename T , typename Y>
auto foo (T x , Y y) -> decltype(x > y ? x : y )
{
    if (x > y)
        return x;
    return y; 
}

template <typename T , typename Y>
auto add (T x , Y y) -> decltype(x + y )
{
    return x +y;
}


// auto bar(){
//     int u ;
//     int v ;
//     cin >> u;
//     cin >> v;
//     if (v > u)
//         return v
//     return false;
// }

struct TR{int x = 4;};

auto give_something(bool mybool) 
{
    int *i = new int(5);
    float *f = new float(1.55);
    return mybool == true ? *f : *i;
}

int main()
{

    cout << numeric_limits<unsigned short>::max() << endl;
    auto val = numeric_limits<unsigned short>::max(); // typically 65,536
    auto sum = add(val, val);
    cout << sum << endl;
    cout << typeid(sum).name() << endl;
    
    cout << numeric_limits<int>::max() << endl;
    cout << numeric_limits<long long>::max() << endl;

    return 0;

}

// auto and decltype works mysteriously !!
// 







