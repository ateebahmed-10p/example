#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class dim
{
    public : 
        int x , y, z = 0;
    
    dim(){
        cout << " I am the default constructor! " << endl;
    }

    dim(int x , int y , int z)
        : x(x), y(y), z(z)
    {
        cout << "I am made!" << endl;
    }

    dim(const dim& other)
    {
        cout << " Executing copy constructor! " << endl;
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }

    ~dim()
    {
        cout << x << y << z << endl;
        cout << " I am the destructor!!" << endl;
    }

    void print()
    {
        cout << x << y << z << endl; 
    }
};

int main()
{
    std::vector<dim> v(3);
    v.push_back(dim(7,8,9));
}