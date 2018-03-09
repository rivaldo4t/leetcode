#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
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
    void nextPermutation(vector<int>& nums) 
    {
        int i;
        for(i = nums.size()-1; i > 0; --i)
            if(nums[i] > nums[i-1])
                break;
        
        if(i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j;
        for(j = i; j < nums.size(); ++j)
            if(nums[i-1] >= nums[j])
                break;
    
        // LOG1(i);LOG1(j);LOG2("");
        swap(nums[i-1], nums[j-1]);
        reverse(nums.begin()+i, nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,5,1};
    s.nextPermutation(nums);
    for(auto i:nums)
        LOG1(i);
    LOG2("");
    return 0;
}