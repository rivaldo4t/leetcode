#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator 
{
public:
    TreeNode* head = NULL;
    stack<TreeNode> s;
    
    void pushLeft(TreeNode* root)
    {
        if(root == NULL)
            return;
        s.push(*root);
        pushLeft(root->left);
    }
    
    BSTIterator(TreeNode *root) 
    {
        head = root;
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode temp = s.top();
        s.pop();
        pushLeft(temp.right);
        return temp.val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
    TreeNode *head = new TreeNode(50);
    head->left = new TreeNode(40);
    head->left->left = new TreeNode(20);
    head->left->right = new TreeNode(45);
    head->right = new TreeNode(60);
    head->right->left = new TreeNode(55);
    head->right->right = new TreeNode(70);
    
    BSTIterator i = BSTIterator(head);
    while (i.hasNext()) 
        cout << i.next() << endl;
    
    return 0;
}