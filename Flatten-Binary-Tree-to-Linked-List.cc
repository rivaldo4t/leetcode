#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    void recur(vector<int>& trav, TreeNode* root)
    {
        TreeNode* temp = root;
        if (temp == NULL)
            return;
        trav.push_back(temp->val);
        recur(trav, temp->left);
        recur(trav, temp->right);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> trav;
        recur(trav, root);
        return trav;
    }
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
            return;
            
        vector<int> trav = preorderTraversal(root);
        
        TreeNode* ptr = root;
        ptr->val = trav[0];
        for(int i = 1; i < trav.size(); i++)
        {
            if(ptr->left)
            {
                delete (ptr->left);
                ptr->left = NULL;
            }
            
            if(ptr->right == NULL)
            {
                TreeNode* temp = new TreeNode(trav[i]);
                ptr->right = temp;
            }
            else
                ptr->right->val = trav[i];
                
            ptr = ptr->right;
        }
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
    head->right = new TreeNode(5);
    head->right->right = new TreeNode(6);

    s.flatten(head);
    
    return 0;
}