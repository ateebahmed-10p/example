#include <iostream>
#include <vector>
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



Widget&& getWidget(){
    return Widget(69);
}

void g(const Widget& w){
    cout << "G is called!!" << endl;
}

template<typename T>
auto foo(T a , T b) 
{
    return "abc";
}



int main() 
{
    Widget u(1);
    Widget v(2);
    
    Widget w = std::move(v);
    cout << v.i << endl;
    //cout << "the addr of v is : " << &v << endl;
    //vector<Widget> container;
    //this should run a move-constructor..
    //std::move converts an object to its rValue reference (o&&)
    //container.push_back( std::move(v) );
    //Widget k(4);
    //cout << "the addr of k is : " << &k << endl;
    //v = std::move(k);
    //cout << "the addr of v is : " << &v << endl;

    //g( getWidget() );
    //cout << foo(2,332) << endl;
    return 0;
}