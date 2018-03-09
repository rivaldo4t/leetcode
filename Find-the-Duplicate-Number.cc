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
    int findDuplicate(std::vector<int>& nums) 
    {
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        int slow2 = nums[0];
        while(slow != slow2)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};

int main()
{
    Solution s;
    LOG2(s.findDuplicate(*(new std::vector<int> {4, 2, 1, 2, 3, 2})));
    return 0;
}