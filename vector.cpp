#include <iostream>
#include <vector>
using namespace std;

void foo(int& a){}
void foo(int a){}

int main()
{
    // auto type deductions rules : 
        // 1. If the initializing expression is a reference (&), it will be removed.
        // 2. If there is const or volatile in initializing expression it will also be removed.
    // template type deduction also works the same way!
    /*
        template <typename T>
        void Foo( T arg ){}


    */
    int a = 5;
    auto& ra = a;
    foo(a);
    return 0;
}