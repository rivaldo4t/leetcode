#include <iostream>
#include <vector>
#include <stack>
#define LOG1(x) std::cout << x
#define LOG2(x) std::cout << x << std::endl

class Solution 
{
    int ans;
    void recur(std::vector<int>& nums, int S, int index)
    {
        if(index == nums.size())
        {
            if(S == 0)
                ans++;
            return;
        }
        
        recur(nums, S - (1 * nums[index]), index + 1);
        recur(nums, S - (-1 * nums[index]), index + 1);
    }
public:
    int findTargetSumWays(std::vector<int>& nums, int S) 
    {
        if(nums.size() == 0)
            return 0;
        
        ans = 0;
        recur(nums, S, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<int> temp = {1, 1, 1, 1, 1};
    LOG2(s.findTargetSumWays(temp, 3));
    return 0;
}