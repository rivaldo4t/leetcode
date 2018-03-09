#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

#define LOG1(x) std::cout << x
#define LOG2(x) std::cout << x << std::endl

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
    void recur(TreeNode* root, int& sumGreater)
    {
        if(root == NULL)
            return;
            
        recur(root->right, sumGreater);
        sumGreater += root->val;
        root->val = sumGreater;
        recur(root->left, sumGreater);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        int sumGreater = 0;
        
        // recursive
        // recur(root, sumGreater);
        
        //iterative
        std::stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(!stk.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                stk.push(curr);
                curr = curr->right;
            }
            curr = stk.top();
            stk.pop();
            sumGreater += curr->val;
            curr->val = sumGreater;
            curr = curr->left;
        }
        return root;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right = new TreeNode(6);
    head->right->left = new TreeNode(5);
    
    TreeNode* root = s.convertBST(head);
    LOG2(root->left->left->val);
    
    return 0;
}