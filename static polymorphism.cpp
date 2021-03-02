#include <iostream>
using namespace std;

class Generic
{
    public:
        // func 1
        void parser(int a)
        {
            return adder(a);
        }
        // func 2
        virtual int adder(int a){};
};

// class one
class Derived : public Generic
{
    public:
        // func 1
        int adder(int a)
        {
            return a+2;
        }
};


int main()
{
    Derived d;
    cout << d.adder(4) << endl;
    return 0;
}




