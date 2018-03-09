#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl

class Solution 
{
public:
    int coinChangeDP(std::vector<int>& coins, int amount) 
    {
        if(coins.size()==0)
            return -1;
            
        // 2D DP
        // std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount+1, 100000));
        // for(int i = 0; i < dp.size(); i++)
        //     dp[i][0] = 0;
        
        // for(int i = 0; i < dp.size(); i++)
        // {
        //     for(int j = 1; j < dp[0].size(); j++)
        //     {
        //         if(i >= 1)
        //             dp[i][j] = dp[i-1][j];
        //         if(j >= coins[i])
        //             dp[i][j] = std::min(dp[i][j], 1+dp[i][j-coins[i]]);
        //     }
        // }
        
        // for(auto i:dp)
        // {
        //     for(auto j:i)
        //         LOG1(j);
        //     LOG2("");
        // }
        // return dp[coins.size()-1][amount] >= 100000 ? -1 : dp[coins.size()-1][amount];
        
        std::vector<int> dp(amount+1, amount+1);
        
        dp[0] = 0;
        
        // 1D DP
        // for(int i = 1; i <= amount; i++)
        //     for(int j = 0; j < coins.size(); j++)
        //         if(i >= coins[j])
        //             dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
        
        // 1D DP optimized
        for(int j = 0; j < coins.size(); j++)
            for(int i = coins[j]; i <= amount; i++)
                dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
                    
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    //recursive using culling when a branch is going to yield worse result
    void recur(std::vector<int>& coins, int amount, int start, int count, int& currResult)
    {
        if(count + ceil(amount*1.0/coins[start]) >= currResult)
            return;
            
        if(amount == 0)
        {
            currResult = std::min(currResult, count);
            return;
        }
        
        for(int i = start; i < coins.size(); i++)
            if(amount >= coins[i])
                recur(coins, amount - coins[i], i, count+1, currResult);
    }
    int coinChange(std::vector<int>& coins, int amount)
    {
        int currResult = amount + 1;
        std::sort(coins.begin(), coins.end(), std::greater<int>());
        recur(coins, amount, 0, 0, currResult);
        return currResult > amount ? -1 : currResult;
    }
    
};

int main()
{
    Solution s;
    std::vector<int> coins = {186, 419, 83, 408};
    LOG2(s.coinChange(coins, 6249));
    return 0;
}