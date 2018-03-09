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
    void recur(vector<int>& trav, TreeNode* root)
    {
        TreeNode* temp = root;
        if (temp == NULL)
            return;
        recur(trav, temp->left);
        trav.push_back(temp->val);
        recur(trav, temp->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> trav;
        stack<TreeNode*> st;
        
        TreeNode* temp = root;
        
        while(temp!=NULL || !st.empty())
        {   
            while(temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            trav.push_back(temp->val);
            temp = temp->right;
        }
        
        //recur(trav, root);
        return trav;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->right->left = new TreeNode(3);
    
    vector<int> trav = s.inorderTraversal(head);
    for(auto &i: trav)
        cout << i << " ";
    cout << endl;
    return 0;
}