#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(s==NULL && t==NULL)
            return true;
        else if(s==NULL || t==NULL || s->val != t->val)
            return false;
            
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if(s==NULL)
            return false;
        if(isSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
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
    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    
    LOG2(s.isSubtree(head, root));
    
    return 0;
}