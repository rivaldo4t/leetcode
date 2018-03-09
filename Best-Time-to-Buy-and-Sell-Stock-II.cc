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
        int max_profit = 0;
        //for(int i = 0; i < prices.size()-1; i++)
        //prices.size() is unsigned int; when you subtract 1 it goes to int_max
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                max_profit += prices[i]-prices[i-1];
            else
                continue;
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