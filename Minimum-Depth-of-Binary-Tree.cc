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
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        if(root->right == NULL && root->left == NULL)
            return 1;
     
        else if(root->left == NULL)
            return 1+minDepth(root->right);
            
        else if(root->right == NULL)
            return 1+minDepth(root->left);
            
        else
            return 1+std::min(minDepth(root->left), minDepth(root->right));
    }
};

int main()
{
    Solution s;
    
    TreeNode *head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->left = new TreeNode(2);
    head->right->left = new TreeNode(3);
    
    LOG2(s.minDepth(head));
    
    return 0;
}