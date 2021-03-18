#include <iostream>
#include <functional>
using namespace std;


struct Bar
{
    Bar(int a ) { this->a = a;}
    void print_add(int i) const { cout << this->a + i << endl;}
    int a ;
};

void print_num(int i)
{
    cout << i << endl;
}

struct PrintNum
{
    int a;
    // define copy constructor
    PrintNum(){}
    PrintNum(int a ){this->a = a;}

    PrintNum(const PrintNum& p)
    {
        this->a = p.a; 
        cout << "running the copy constructor!" << endl;
    }
    PrintNum operator()(int i )
    {
        cout << i << endl;
        PrintNum p;
        return  p;
    }
    operator int() const { return this->a ;}
};

int main(){
    // PrintNum p;
    // PrintNum a = p(5); // return value optimization (RVO) in action..

    // USE OF STD :: FUNCTION. A WRAPPER TO RAW FUNCTION POINTERS !! (SYNTACTIC SUGAR)
    std::function<void(int)> f = print_num;
    f(-5);

    std::function<void()> f_display_69 = [](){cout << 69 << endl;};
    f_display_69();

    std::function<void(const Bar&, int)> mem_function = Bar::print_add;
    const Bar b(112);
    mem_function(b,8) ;
    mem_function(b,1123) ;

    PrintNum p(1318122);
    cout << int(p) << endl;
    

    return 0;
}