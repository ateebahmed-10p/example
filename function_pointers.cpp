#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T Double(T item ){ return item*2; }

template <typename T , typename R>
void Apply(T& vec , R(*predicate)(R) )
{
    for (typename T::iterator i = vec.begin(); i != vec.end() ; i++) // make the freaking code more difficult to read!! :D
    {
        *i = predicate(*i);
        cout << *i << endl;
    } 
}


int main()
{  
    std::vector<int> a = {1,2,3,4,55};
    Apply<decltype(a) , int>(a , Double<int>); 
    return 0;
}