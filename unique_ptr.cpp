#include <iostream>
#include <memory>
using namespace std;

class Cat
{
    string name_;
    public:
        Cat () {cout << "jungli billi !!" << endl; this->name_ = "jungli billi";}
        Cat(string s) {this->name_ = s; cout << "making a kitten named: " + s << endl;}
        ~Cat(){cout << this->name_ <<" has been killed!" << endl;}
        Cat(const Cat& other) {this->name_ = other.name_; cout << "kitten has been copied!" << endl;}
        void bark(){
            cout << this->name_ <<" do not bark!!" << endl;
        }
};

void foo(unique_ptr<Cat> ptr)
{
    //ptr->bark();
}

unique_ptr<Cat> bar(unique_ptr<Cat> p)
{
    return p;
}





int main ()
{
    unique_ptr<Cat> c(new Cat("tiger shroff"));
    c->bark();
    //foo(c); // lol wont compile. copy constructor of unique_ptr is deleted!!
    //foo(std::move(c)); // move semantics works.
    unique_ptr<Cat> c2 = bar(std::move(c));

    return 0 ;
}