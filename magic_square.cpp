#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_GRID_COUNT = 8;

std::vector<std::vector<std::vector<int>>> GRIDS = {  
                                        {{4,3,8} , {9,5,1} , {2,7,6}} ,
                                        {{8,3,4}, {1,5,9} , {6,7,2}} ,
                                        {{2,7,6}, {9,5,1} , {4,3,8}}  ,
                                        {{6,7,2}, {1,5,9} , {8,3,4}} ,
                                        {{8,1,6} , {3,5,7} , {4,9,2}} ,
                                        {{6,1,8}, {7,5,3} , {2,9,4}} ,
                                        {{4,9,2}, {3,5,7} , {8,1,6}}  ,
                                        {{2,9,4}, {7,5,3} , {6,1,8}} ,
                                    };

int calc_cost(auto& target , auto& candidate)
{
    int cost = 0;
    // do the diffing here
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (target[i][j] != candidate[i][j])
            {
                //add it into the cost
                cost += std::abs(candidate[i][j] - target[i][j]);
            }
        }
    }

    return cost;
}


auto formingMagicSquare(auto& target)
{
    std::vector<int> scores = {66,33,1,0,3,2,0,0}; 
    // iterate over all grids :
    for (int i = 0 ; i < GRIDS.size() ; i++)
    {
        scores[i] = calc_cost(target , GRIDS[i]);
    }

    return scores;
}



int main()
{
    std::vector<std::vector<int>> target = {{5,3,4}, {1,5,8}, {6,4,2}};
    auto i = formingMagicSquare(target);

    // finally
    // min_element returns an iterator of vector type
    auto minimum_cost = min_element(i.begin() , i.end());
    cout << *minimum_cost << endl;
    return 0;
}