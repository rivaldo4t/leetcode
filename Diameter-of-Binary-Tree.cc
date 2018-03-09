#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <climits>

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
// O(N^2)
//     int maxDepth(TreeNode* root)
//     {
//         if(root == NULL)
//             return 0;
//         return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
//     }
//     void recur(TreeNode* root, int& diameter)
//     {
//         if(root == NULL)
//             return;
//         int left = maxDepth(root->left);
//         int right = maxDepth(root->right);
//         diameter = std::max(diameter, left + right);
//         recur(root->left, diameter);
//         recur(root->right, diameter);
//     }
// public:
//     int diameterOfBinaryTree(TreeNode* root) 
//     {
//         int diameter = INT_MIN;
//         recur(root, diameter);
//         return std::max(0, diameter);
//     }

// O(N)
    int diameter;
    int recur(TreeNode* root)
    {
        if(root == NULL)
            return 0;
            
        int left = recur(root->left);
        int right = recur(root->right);
        
        diameter = std::max(diameter, left + right);
        
        return 1 + std::max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        diameter = 0;
        recur(root);
        return diameter;
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
    
    LOG2(s.diameterOfBinaryTree(head));
    
    return 0;
}