#include <iostream>
using namespace std;

class Widget
{
    public : 
        int i;
        Widget(){}
        Widget(int i){
            this->i = i;
            cout << this->i << endl;
        }

        // copy constructor
        Widget(const Widget& rhs){
            cout << "copy constructor is running!!" << endl;
            this->i = rhs.i;
        }
        // move operator
        Widget& operator=(Widget&& rhs)
        {
            cout << "this is the move operator!" << endl;
            return *this;
        }
        // move constructor
        Widget(Widget&& rhs) noexcept
        {
            cout << "this is the move constructor!" << endl;
            this->i = rhs.i;
            rhs.i = 0;
        }
        // copy operator
        Widget& operator=(const Widget& rhs)
        {
            cout << "this is the copy operator!" << endl;
            this->i = rhs.i;
            return *this;
        }
        void setI(int i){
            this->i = i;
        }
};


template <class T>
void Foo (T&& a) {
    // this is rvalue ref i.e. the compiler will try perfect forwarding.
    a.i = 69;
    cout << a.i << endl;
}

void fool(const Widget& a){
    cout << "hi" << endl;
}

void Fool(int&& a){
    cout << a << endl;
}

int main () {
    Widget u(1);
    Widget&& rvr_u = Widget(2);
    fool(std::move(u));
    return 0;
}