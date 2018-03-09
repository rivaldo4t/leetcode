#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
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

    /*
    //Top Down O(N*N)
    int subDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
            
        int temp1 = 0, temp2 = 0;
        temp1 = subDepth(root->left) + 1;
        temp2 = subDepth(root->right) + 1;
        //cout << "subDepth " << temp1 << " " << temp2 << endl;
        return max(temp1, temp2);
    }

    bool isBalanced(TreeNode* root) 
    {
        if (root == NULL)
            return true;
        
        int temp = subDepth(root->right) - subDepth(root->left);
        temp = abs(temp);
        //cout << temp << endl;
        if(temp <= 1)
        {
            return isBalanced(root->right) && isBalanced(root->left);
        }
        else
            return false;
    }
    */
    
    //Bottom Up O(N)
    
    int dfsDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
            
        int left = dfsDepth(root->left);
        if(left == -1)
            return -1;
        int right = dfsDepth(root->right);
        if(right == -1)
            return -1;
        if(abs(left - right) > 1)
            return -1;
        else 
            return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root)
    {
        return dfsDepth(root) != -1;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->left->left = new TreeNode(4);
    head->left->left->right = new TreeNode(5);
    head->right = new TreeNode(6);
    

    cout << s.isBalanced(head) << endl;
    
    return 0;
}