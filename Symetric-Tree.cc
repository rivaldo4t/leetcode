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
    bool recur(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        else if (left !=NULL && right !=NULL)
        {
            if(left->val != right->val)
                return false;
            return recur(left->left, right->right) && recur(left->right, right->left);
        }
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return 1;
        return recur(root->left, root->right);
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->left = new TreeNode(3);
    cout << s.isSymmetric(head) << endl;
    return 0;
}