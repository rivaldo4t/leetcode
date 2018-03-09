#include <iostream>
#include <vector>
#include <stack>
#include <deque>
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
    vector<vector<int>> BFSresult;
    void BFS(TreeNode* root, int level)
    {
        if(root == NULL)
            return;
        if(level == BFSresult.size())
            BFSresult.push_back(vector<int>());
        
        BFSresult[level].push_back(root->val);
        BFS(root->left, level+1);
        BFS(root->right, level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> LevelOrder;
        if(!root)
            return LevelOrder;
        // how did i think this
        // deque<TreeNode*> Q, P;
        // Q.push_back(root);
        // vector<int> thisLevel;
        // while(1)
        // {
        //     if(Q.empty())
        //     {
        //         LevelOrder.push_back(thisLevel);
        //         thisLevel.clear();
        //         Q = P;
        //         P.clear();
        //     }
        //     if(Q.empty() && P.empty())
        //         break;
        //     TreeNode* temp = Q.front();
        //     thisLevel.push_back(temp->val);
        //     Q.pop_front();
        //     if(temp->left) 
        //         P.push_back(temp->left);
        //     if(temp->right) 
        //         P.push_back(temp->right);
        // }
        // reverse(LevelOrder.begin(), LevelOrder.end());
        
        // from discussions on Leetcode
        // DFS
        // deque<TreeNode*> q;
        // q.push_back(root);
        // while(!q.empty())
        // {
        //     int n = q.size();
        //     vector<int> temp;
        //     for(int i = 0; i < n; i++)
        //     {
        //         TreeNode* node = q.front();
        //         if(node->left)
        //             q.push_back(node->left);
        //         if(node->right)
        //             q.push_back(node->right);
        //         temp.push_back(node->val);
        //         q.pop_front();
        //     }
        //     LevelOrder.push_back(temp);
        // }
        // reverse(LevelOrder.begin(), LevelOrder.end());
        // return LevelOrder;
        
        // BFS
        BFS(root, 0);
        reverse(BFSresult.begin(), BFSresult.end());
        return BFSresult;
    }
};

int main()
{
    Solution s;
    
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(4);
    
    vector<vector<int>> a = s.levelOrderBottom(head);
    for(auto i:a)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
        
    }
    
    return 0;
}