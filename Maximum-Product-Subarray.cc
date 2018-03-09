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
    int maxProduct(std::vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        
        if(nums.size() == 1)
            return nums[0];
        
        std::vector<int> prod = nums;
        
        int prevNegMax = 1;
        for(int i = 1; i < prod.size(); i++)
        {
            int temp1 = prod[i] * prod[i-1];
            int temp2 = prod[i] * prevNegMax;
            
            prevNegMax = std::min(std::min(temp1, temp2), prod[i]);
            prod[i] = std::max(std::max(temp1, temp2), prod[i]);
            
            // LOG1(prod[i]);
            // LOG1(prevNegMax);
            // LOG2("");
        }
        
        int maxProd = INT_MIN;
        for(auto i:prod)
        {
            // LOG1(i);
            if(i > maxProd)
                maxProd = i;
        }
        // LOG2("");
        return maxProd;
    }
};

int main()
{
    Solution s;
    std::vector<int > nums = {2,-5,-2,-4,3};
    LOG2(s.maxProduct(nums));
    return 0;
}