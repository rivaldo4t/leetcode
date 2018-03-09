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
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        // our solution
        // if(nums.size() == 0)
        //     return 0;
            
        // int num = nums[0];
        // int dup = 1;
        // int dupAllowed = 2;
        // int index = 1;
        
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(num == nums[i])
        //     {
        //         if(dup < dupAllowed)
        //         {
        //             dup++;
        //             nums[index] = nums[i];
        //             index++;
        //         }
        //     }
        //     else
        //     {
        //         num = nums[i];
        //         dup = 1;
        //         nums[index] = num;
        //         index++;
        //     }
        // }
        // return index;
        
        // leet
        int index = 0;
        for(auto i:nums)
            if(index < 2 || i > nums[index-2])
                nums[index++] = i;
                
        return index;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1,1,1,2,2,3};
    LOG2(s.removeDuplicates(nums));
    return 0;
}