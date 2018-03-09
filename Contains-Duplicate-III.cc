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
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) 
    {
        // TLE
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     for(int j = i+1; j <= i+k && j < nums.size(); j++)
        //     {
        //         if((abs((long)nums[j]-(long)nums[i])) <= t)
        //             return true;
        //     }
        // }
        // return false;
        
        // long to avoid overflow
        std::set<long> window;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k)
                window.erase(nums[i-k-1]);
            auto pos = window.lower_bound((long)nums[i] - (long)t);
            if(pos != window.end() && (*pos <= (long)nums[i] + (long)t))
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 5, 9, 7};
    LOG2(s.containsNearbyAlmostDuplicate(nums, 2, 3));
    return 0;
}