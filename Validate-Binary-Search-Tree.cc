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
        recur(trav, temp->left);
        trav.push_back(temp->val);
        recur(trav, temp->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> trav;
        recur(trav, root);
        return trav;
    }
    bool isValidBST60ms(TreeNode* root) 
    {
        vector<int> a = inorderTraversal(root);
        vector<int> b = a;
        
        sort(a.begin(), a.end());
        
        for(auto& i : a)
            cout << i << " ";
        cout << endl;
        for(auto& i : b)
            cout << i << " ";
        cout << endl;
        
        if(a==b)
        {
            auto pos = adjacent_find(a.begin(), a.end());
            if (pos != a.end())
                return false;
            else
                return true;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        vector<int> a = inorderTraversal(root);
        if(a.size() == 0)
            return true;
        for(int i = 0; i < a.size()-1; i++)
            if(a[i+1] <= a[i])
                return false;    
        return true;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(2);
    head->left = new TreeNode(1);
    head->right = new TreeNode(3);

    cout << s.isValidBST(head) << endl;
    
    return 0;
}