#include <iostream>
#include <vector>
using namespace std;


int main()
{
    std::vector<std::vector<std::vector<int>>> a = {  
                                     {{4,3,8} , {9,5,1} , {2,7,6}} ,
                                     {{8,3,4}, {1,5,9} , {6,7,2}} ,
                                     {{2,7,6}, {9,5,1} , {4,3,8}}  ,
                                     {{6,7,2}, {1,5,9} , {8,3,4}} ,
                                     {{8,1,6} , {3,5,7} , {4,9,2}} ,
                                     {{6,1,8}, {7,5,3} , {2,9,4}} ,
                                     {{4,9,2}, {3,5,7} , {8,1,6}}  ,
                                     {{2,9,4}, {7,5,3} , {6,1,8}} ,
                                    };

    for (auto i = a.begin() ; i != a.end() ; i++)
    {
        for (auto j = i->begin() ; j != i->end() ; j++)
        {
            for (auto k = j->begin() ; k != j->end() ; k ++)
                cout << *k << endl;
        }
    }

    return 0;
}
