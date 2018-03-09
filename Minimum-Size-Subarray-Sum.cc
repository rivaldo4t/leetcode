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
public:
    int minSubArrayLen(int s, std::vector<int>& nums) 
    {
        int minSub = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        
        for(int end = 0; end < nums.size();)
        {
            sum += nums[end];
            if(sum >= s)
            {
                minSub = std::min(minSub, end - start + 1);
                sum -= nums[start]; // decrease the window and see if still sum >= s
                sum -= nums[end]; // will be added again in next iteration; thus subtracting now
                start++;
            }
            else
                end++;
        }
        return minSub == INT_MAX ? 0 : minSub;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {2,3,1,2,4,3};
    LOG2(s.minSubArrayLen(7, nums));
    return 0;
}