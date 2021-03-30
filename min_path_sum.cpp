#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    int calc(vector<vector<int>> &grid , vector<vector<int>> &cache , int curr_row , int curr_idx)
    {
        if (cache[curr_row][curr_idx] != -1)
            return cache[curr_row][curr_idx];
        
        if (curr_row == grid.size() - 1 and curr_idx == grid[0].size() -1)
            return grid[curr_row][curr_idx];

        int down = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::max();

        if (curr_row != grid.size() - 1)
            down = grid[curr_row][curr_idx] + this->calc(grid, cache ,curr_row + 1, curr_idx);

        if (curr_idx != grid[0].size() -1)
            right = grid[curr_row][curr_idx] + this->calc(grid, cache, curr_row , curr_idx + 1);

        if (down < right)
        {
            cache[curr_row][curr_idx] = down;
            return down;
        }

        cache[curr_row][curr_idx] = right;
        return right;
    }
    int minPathSum(vector<vector<int>>& grid) {
        // initializing the cache storage
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> cache (n , vector<int>(m , -1));
        
        return this->calc(grid, cache, 0, 0);
    }
};



int main()
{
    
    Solution S;
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    cout << S.minPathSum(grid) << endl;
    return 0;
}