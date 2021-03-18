#include <iostream>
using namespace std;

struct AddVal
{
    int val = 0;
    AddVal(int a) {this->val = a;}
    void operator() (int a)
    {
        cout << val + a << endl; 
    }
};








int main()
{
    AddVal f(5); // will add 5 to whatever you call it with.
    f(5);

    AddVal t(10);
    t(5);

    return 0;
}