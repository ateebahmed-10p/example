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

// SHARED POINTER


int main(){
    shared_ptr<Cat> c(new Cat("arya"));
    cout << c.use_count() << endl;
    {
        shared_ptr<Cat> c1 = c;
        cout << c.use_count() << endl;    // ref_count = 2
        shared_ptr<Cat> c2 = c;
        cout << c.use_count() << endl; // // ref_count = 3
    }
    cout << c.use_count() << endl; // // ref_count = 1


    // THE PREFERRED WAY OF USING INITIALIZING A SHARED POINTER!!
    shared_ptr<Cat> c3 = make_shared<Cat>("shamim");
    cout << c3.use_count() << endl; // // ref_count = 1
    
    // CUSTOM DELETER is very useful with shared_pointers!!
    Cat* c_arr = new Cat[3];
    shared_ptr<Cat> c_ptr( c_arr , [](Cat* p){cout << "calling the custom delete!!" << endl; delete[] p; }); //shared_pointer constructor overload which takes a lambda deleter function!


    // all these variables will free dynamic memory once they go out of scope!
    return 0;
}