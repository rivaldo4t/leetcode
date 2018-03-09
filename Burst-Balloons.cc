#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <queue>
#include <list>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl
using namespace std;

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
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp (nums.size(), vector<int>(nums.size(), 0));
        
        for(int len = 1; len <= n; ++len)
        {
            for(int left = 1; left <= n-len+1; ++left)
            {
                int right = left+len-1;
                for(int i = left; i <= right; ++i)
                {
                    dp[left][right] = max(dp[left][right],
                                        nums[left-1]*nums[i]*nums[right+1] + dp[left][i-1] + dp[i+1][right]);
                                        
                    // for(auto i:dp)
                    // {
                    //     for(auto j:i)
                    //         LOG1(j);
                    //     LOG2("");
                    // }
                    // LOG2("");
                }
            }
        }
        
        return dp[1][n];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 1, 5, 8};
    LOG2(s.maxCoins(nums));
    return 0;
}