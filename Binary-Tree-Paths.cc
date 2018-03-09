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

    void recur(vector<string>& res, TreeNode* root, string str)
    {
        if(!root->left && !root->right)
        {
            res.push_back(str);
            return;
        }
        
        if(root->left)
            recur(res, root->left, str + "->" + to_string(root->left->val));
        if(root->right)
            recur(res, root->right, str + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if(root == NULL)
            return res;
        
        recur(res, root, to_string(root->val));
        
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->right = new TreeNode(5);
    auto t = s.binaryTreePaths(head);
    for(auto i:t)
        cout << i << endl;
    return 0;
}