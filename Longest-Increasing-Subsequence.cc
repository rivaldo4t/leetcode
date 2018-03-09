#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:

    int max(int a, int b)
    {
        return a>b?a:b;
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        vector<int> dp (nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        
        int ans = -1;
        for(auto i:dp)
            if(i > ans)
                ans = i;
                
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(a) << endl;
    return 0;
}