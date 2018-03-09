#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    int maxProfit(std::vector<int>& prices) 
    {
        if(prices.size() < 2)
            return 0;
        // 160 / 200; wrong approach
        // int currProfit = 0, lastProfit = 0, maxProfit = 0;
        // bool coolDown = false;
        
        // for(int i = 1; i < prices.size(); ++i)
        // {
        //     currProfit = prices[i] - prices[i-1];
            
        //     if(coolDown == true && currProfit > 0)
        //     {
        //         if(currProfit > lastProfit)
        //         {
        //             maxProfit += currProfit - lastProfit;
        //             coolDown = false;
        //         }
        //     }
        //     else if(currProfit > 0)
        //     {
        //         maxProfit += currProfit;
        //         lastProfit = currProfit;
        //     }
        //     else
        //     {
        //         if(maxProfit != 0)
        //             coolDown = !coolDown;
        //     }
        // }
        // return maxProfit;
        
        int buy_i = -prices[0], buy_i_minus_1 = buy_i;
        int sell_i = 0, sell_i_minus_1 = 0, sell_i_minus_2 = 0;
        
        for(auto price : prices)
        {
            buy_i = std::max(buy_i_minus_1, sell_i_minus_2 - price);
            sell_i = std::max(sell_i_minus_1, buy_i_minus_1 + price);
            
            buy_i_minus_1 = buy_i;
            sell_i_minus_2 = sell_i_minus_1;
            sell_i_minus_1 = sell_i;
        }
        return std::max(buy_i, sell_i);
    }
};

int main()
{
    Solution s;
    std::vector<int> prices = {2, 1, 2, 0, 1};
    LOG2(s.maxProfit(prices));
    return 0;
}