#include <iostream>
#include <memory>
using namespace std;

class Cat
{
    private :
        string name_;
        // shared_ptr<Cat> friend_;
        weak_ptr<Cat> friend_;

    public:
        Cat () {cout << "wild cat !!" << endl; this->name_ = "wild cat";}
        Cat(string s) {this->name_ = s; cout << "making a kitten named: " + s << endl;}
        ~Cat(){cout << this->name_ <<" has been killed!" << endl;}
        Cat(const Cat& other) {this->name_ = other.name_; cout << "kitten has been copied!" << endl;}
        void bark(){
            cout << this->name_ <<" do not bark!!" << endl;
        }
        void make_friend(shared_ptr<Cat> other) {this->friend_ = other;}
        void show_friend()
        {
            // lock() creates a shared pointer out of weak_ptr. to avoid delete.
            cout << "my friend is : " << this->friend_.lock()->name_ << endl;
        }
};


int main()
{
    // make two shared Pointers
    shared_ptr<Cat> at = make_shared<Cat>("At");
    shared_ptr<Cat> am = make_shared<Cat>("Am");

    at->make_friend(am);
    am->make_friend(at); 
    // after the program executes none of the shared_ptrs are deleted. due to cyclic reference..
    // cout << at.use_count() << endl; // 2 
    // cout << am.use_count() << endl;  // 2

    // to remedy this, use weak_ptr. weak_ptr doesnt take ownership of assigned raw pointer, it just uses it.
    at->show_friend();
    am->show_friend();

}