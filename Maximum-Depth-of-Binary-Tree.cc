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
    int max(int a, int b)
    {
        return a>b?a:b;
    }
    int recur(TreeNode* root, int depth)
    {
        if(root == NULL)
            return depth;
        int d = depth+1;
        return max(recur(root->left, d), recur(root->right, d));
    }
    int maxDepth(TreeNode* root) 
    {
        return recur(root, 0);
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->left = new TreeNode(2);
    head->right->left = new TreeNode(3);
    
    cout << s.maxDepth(head) << endl;
    return 0;
}