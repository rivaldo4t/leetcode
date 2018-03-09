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
    int minIndex, maxIndex;
    void binarySearch(std::vector<int> nums, int target, int low, int high)
    {
        if(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
            {
                if(mid < minIndex)
                {
                    minIndex = mid;
                    binarySearch(nums, target, low, mid-1);
                }
                if(mid > maxIndex)
                {
                    maxIndex = mid;
                    binarySearch(nums, target, mid+1, high);
                }
            }
            else if(nums[mid] < target)
                binarySearch(nums, target, mid+1, high);
            else
                binarySearch(nums, target, low, mid-1);
        }
        
    }
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) 
    {
        std::vector<int> temp;
        minIndex = INT_MAX;
        maxIndex = INT_MIN;
        binarySearch(nums, target, 0, nums.size()-1);
        if(minIndex == INT_MAX && maxIndex == INT_MIN)
            minIndex = -1, maxIndex = -1;
        return std::vector<int> {minIndex, maxIndex};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {5, 6, 6, 7, 7, 8, 8, 8, 10};
    std::vector<int> ans = s.searchRange(nums, 9);
    for(auto i:ans)
        LOG1(i);
    LOG2("");
    return 0;
}