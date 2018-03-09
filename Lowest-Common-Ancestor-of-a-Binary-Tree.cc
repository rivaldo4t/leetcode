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

    void findNode(TreeNode* root, TreeNode* x, vector<TreeNode*>& traverseToX)
    {
        if(root == NULL)
            return;
            
        if(root == x)
        {
            traverseToX.push_back(root);
            return;
        }
        else
        {
            traverseToX.push_back(root);
            
            findNode(root->left, x, traverseToX);
            if(traverseToX[traverseToX.size()-1] == x)
                return;
                
            findNode(root->right, x, traverseToX);
            if(traverseToX[traverseToX.size()-1] == x)
                return;
            else
                traverseToX.pop_back();
        }
        return;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> traverseToP;
        findNode(root, p, traverseToP);
        for(auto i:traverseToP)
            cout << i->val << " ";
        cout << endl;
        vector<TreeNode*> traverseToQ;
        findNode(root, q, traverseToQ);
        for(auto i:traverseToQ)
            cout << i->val << " ";
        cout << endl;
        int i;
        for(i = 0; i < traverseToP.size() && i < traverseToQ.size(); i++)
        {
            if(traverseToP[i] == traverseToQ[i])
                continue;
            else
                break;
        }
        
        return traverseToP[i-1];
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->left->left->left = new TreeNode(5);
    head->right = new TreeNode(3);
    head->left->left->right = new TreeNode(6);
    head->left->left->left->right = new TreeNode(7);
    
    cout << s.lowestCommonAncestor(head, head->left->left, head->left->left->left->right)->val;
    cout << endl;
    
    return 0;
}