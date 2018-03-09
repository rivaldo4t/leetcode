#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    
    int findMax(vector<int> nums, int start, int end)
    {
        if(start > end)
            return -1;

        int index = start;
        for(int i = start+1; i <= end; i++)
            if(nums[i] > nums[index])
                index = i;
        
        return index;
    }
    
    TreeNode* recur(vector<int> nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int index = findMax(nums, start, end);
        TreeNode* root = new TreeNode(nums[index]);
        
        root->left = recur(nums, start, index-1);
        root->right = recur(nums, index+1, end);
        
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return recur(nums, 0, nums.size()-1);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* head = s.constructMaximumBinaryTree(nums);
    return 0;
}