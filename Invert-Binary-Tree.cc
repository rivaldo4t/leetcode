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
    void recur(TreeNode* root)
    {
        if(root == NULL)
            return;
        recur(root->left);
        recur(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
            return NULL;
        recur(root->left);
        recur(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);
    TreeNode* inverted = s.invertTree(head);
    return 0;
}