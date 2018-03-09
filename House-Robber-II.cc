#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
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
    int houseRobber(std::vector<int>& nums, int low, int high)
    {
        int rob = 0, notrob = 0;
        for(int i = low; i <= high; i++)
        {
            int currrob = nums[i] + notrob;
            notrob = std::max(notrob, rob);
            rob = currrob;
        }
        return std::max(rob,notrob);
    }
public:
    int rob(std::vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 2)
            return n ? nums[0] : 0;
            
        return std::max(houseRobber(nums, 0, n-2), houseRobber(nums, 1, n-1));
    }
};

int main()
{
    Solution s;
    // std::vector<int> nums = {2,6,1,7,5,4,8,9};
    std::vector<int> nums = {1,1,2,1};
    LOG2(s.rob(nums));
    return 0;
}