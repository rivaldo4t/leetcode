#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int min_num = INT_MAX, max_profit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min_num)
                min_num = prices[i];
            else if(prices[i] - min_num > max_profit)
                max_profit = prices[i] - min_num;
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(nums) << endl;
    return 0;
}