#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(std::vector<int>& height) {
        //for edge cases.
        if (height.empty())
            return 0;
        
        int size = height.size();
        std::vector<int> left (size);
        std::vector<int> right (size);

        // find the max height of the wall to the left of each block
        left[0] = 0;
        for(int i = 1 ; i != size ; i++)
        {
            left[i] = std::max( height[i-1], left[i-1]);
        }
        right[size - 1] = 0;
        for (int i = size - 2 ; i >= 0 ; i--)
        {
            right[i] = std::max(height[i+1], right[i+1]);
        }

        // finally calculating the trapped water
        int water = 0;
        int temp  = 0;
        for (int i = 0 ; i != size ; i++)
        {
            temp = std::min(left[i], right[i]) - height[i];
            if (temp > 0)
                water += temp;
        }
        return water;
    }
};
int main()
{
    Solution S;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << S.trap(height) << endl;
    return 0;
}