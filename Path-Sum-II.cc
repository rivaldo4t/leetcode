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

    void recur(vector<vector<int>>& res, TreeNode* root, int sum, vector<int>& temp, int currSum)
    {
        //this optimization fails for negative numbers in the tree
        // if(currSum > sum)
        //     return;
        if(!root->left && !root->right)
        {
            if(sum == currSum)
                res.push_back(temp);
            return;
        }
        
        if(root->left)
        {
            temp.push_back(root->left->val);
            currSum += root->left->val;
            recur(res, root->left, sum, temp, currSum);
            temp.pop_back();
            currSum -= root->left->val;
        }
        if(root->right)
        {
            temp.push_back(root->right->val);
            currSum += root->right->val;
            recur(res, root->right, sum, temp, currSum);
            temp.pop_back();
            currSum -= root->right->val;
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        vector<int> temp;
        temp.push_back(root->val);
        int currSum = root->val;
        
        recur(res, root, sum, temp, currSum);
        
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(7);
    head->left->right = new TreeNode(5);
    head->left->right->left = new TreeNode(2);
    head->right = new TreeNode(3);
    
    auto t = s.pathSum(head, 4);
    for(auto i:t)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}