#include <iostream>
#include <vector>
using namespace std;

class Base
{
    public:
        virtual void foo(){}
};

class Derived : public Base
{
    public:
        void foo(){}
};

template <typename T>
bool binary_search(std::vector<T>& arr , T s)
{

    int i = 0;
    int j = arr.size();

    while( i < j )
    {
        int mid = i + j / 2;
        if (arr[mid] == s){
            return true;
        }
        else if (arr[mid] > s)
        {   
            j = mid;
        }
        else if (arr[mid] < s)
        {
            i = mid + 1;
        }
    }    
    if (i != arr.size() && arr[i] == s )
        return true;
    
    return false;
}

void print(std::vector<int>& arr)
{
    for (std::vector<int>::iterator i = arr.begin() ; i != arr.end() ; i++)
    {
        cout << *i << " , ";
    }

    cout << endl;
}


int main()
{
    std::vector<int> a;
    a.push_back(3);
    a.push_back(341);
    a.push_back(444);
    a.push_back(556);



    return 0;
}