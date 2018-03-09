#include <iostream>
#include <vector>
#include <stack>
#define LOG1(x) std::cout << x
#define LOG2(x) std::cout << x << std::endl

class Solution 
{
public:
    bool canPartition(std::vector<int>& nums) 
    {
        int sum = 0;
        for(auto i:nums)
            sum += i;
        if(sum & 1 == 1)
            return false;
        sum /= 2;
        
        // std::vector<std::vector<bool>> dp(nums.size()+1, std::vector<bool>(sum+1, false));
        
        // dp[0][0] = true;
        // for(int i = 1; i <= nums.size(); i++)
        //     dp[i][0] = true;
        // for(int i = 1; i <= sum; i++)
        //     dp[0][i] = false;
            
        // for(int i = 1; i <= nums.size(); i++)
        // {
        //     for(int j = 1; j <= sum; j++)
        //     {
        //         dp[i][j] = dp[i-1][j];
        //         if (j >= nums[i-1]) 
        //         {
        //             dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
        //         }
        //     }
        // }
        // return dp[nums.size()][sum];
        
        //didn't get this
        std::vector<bool> dp(sum+1, false);
        dp[0] = true;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = sum; j > 0; j--)
            {
                if(j >= nums[i])
                    dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {2, 1, 1, 1, 1};
    LOG2(s.canPartition(nums));
    return 0;
}