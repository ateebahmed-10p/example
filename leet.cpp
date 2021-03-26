#include <vector>
#include <iostream>
#include <climits>
using namespace std;



class Solution {
public:
    std::vector<std::vector<int>> look_up_table;

    void look_up_init(int size)
    {
        cout << size << endl;
        // making room in the main container
        this->look_up_table.resize(size);
        for (int i = 0 ; i < size ; i++)
        {
            // making room in the row wise containers
            this->look_up_table[i].resize(i+1, INT_MAX);
            // setting each value to be INT_MAX
            // for (int j = 0 ; j < i+1 ; j++)
            //     this->look_up_table[i][j] = INT_MAX;
        }
    }

    int finder(std::vector<std::vector<int>>& triangle , int curr_row , int curr_idx )
    {
        if (curr_row == triangle.size() - 1)
            return triangle[curr_row][curr_idx];
        
        if (this->look_up_table[curr_row][curr_idx] != INT_MAX)
            return this->look_up_table[curr_row][curr_idx];

        int left = triangle[curr_row][curr_idx] + finder(triangle , curr_row + 1 , curr_idx);
        int right = triangle[curr_row][curr_idx] + finder(triangle , curr_row + 1, curr_idx + 1);

        if (left > right)
        {
            this->look_up_table[curr_row][curr_idx] = right;
            return right;
        }

        this->look_up_table[curr_row][curr_idx] = left;
        return left;
    }

    int minimumTotal(vector<vector<int>>& triangle) {   
        this->look_up_init(triangle.size());
        return this->finder(triangle , 0 , 0);
        
    }
};



int main()
{
    std::vector< std::vector<int>> triangle = {{2} , {3,4}, {6,5,7}, {4,1,8,3}};
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}