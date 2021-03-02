#include <iostream>
using namespace std;

template <typename T>
class Generic
{
    public:
        // func 1
        int parser(int a)
        {
            adder(a);
            return 0;
        }
        // func 2
        void adder(int a){
            static_cast<T*>(this)->adder(a);
            // OR 
            /*
            T temp;
            temp.adder(a);
            */

        };
};

// class one
class Derived : public Generic<Derived>
{
    public:
        // func 1
        void adder(int a)
        {
            cout <<  a+4 << endl;
            // Generic::adder(a);
        }
};


int main()
{
    Derived d;
    d.parser(5);    
    return 0;
}




