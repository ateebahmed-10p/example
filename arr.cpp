#include <iostream>
#include <vector>
using namespace std;


class node
{
    public: 
        node(){
            cout << "this is an expensive construction!" << endl;
        }
};


int main()
{
    vector<node> arr(10);
    return 0;
}