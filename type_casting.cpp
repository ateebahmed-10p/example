#include <iostream>
using namespace std;

class Base
{
    public:
        int b = 3;
        void print_base(){cout << "Base Class " << b << endl; }
};
class Derived : public Base
{
    public:
        int d = 2;
        void print_derived(){cout << "Derived Class: " << d << endl; }
};

int main()
{
    const int* n = new int();
    int* m = const_cast<int*>(n);
    return 0;  
}