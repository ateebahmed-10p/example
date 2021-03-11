#include <iostream>
using namespace std;

void goo(int *a)
{
    cout << "passed the pointer by value!" << endl;
    a = new int(96);
}

void foo(int*& b)
{
    cout << "passed the pointer by reference!" << endl;
    b = new int(96);
}

int main()
{
    // passing pointer by value!!
    int* a = new int(6);
    goo(a);
    cout << *a << endl; // value of a is not changed, after the call to goo!
 
    // passing pointer by reference !!
    int* b = new int(6);
    foo(b);
    cout << *b << endl; // value of b is changed, since we passed by reference!

    return -0;
};