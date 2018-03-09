#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <queue>
#include <list>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
    // void recur1(TreeNode* root, vector<vector<int>>& levelOrder, int level)
    // {
    //     if(levelOrder.size() == level)
    //         levelOrder.push_back(vector<int> ());
            
    //     int val = root ? root->val : INT_MAX;
    //     levelOrder[level].push_back(val);
        
    //     if(root)
    //     {
    //         recur1(root->left, levelOrder, level+1);
    //         recur1(root->right, levelOrder, level+1);
    //     }
        
    // }
    
    void recur(TreeNode* root, int level, int pos, int& longestLevel, vector<int>& lefts)
    {
        if(root == NULL)
            return;
        
        if(level >= lefts.size())
            lefts.push_back(pos);
        
        longestLevel = max(longestLevel, pos - lefts[level] + 1);    
        
        recur(root->left, level + 1, pos*2, longestLevel, lefts);
        recur(root->right, level + 1, pos*2 + 1, longestLevel, lefts);
    }
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        // max({1,2,3}) works from C++ 11
        
        // 90 / 110
        // vector<vector<int>> levelOrder;
        // recur(root, levelOrder, 0);
        // int longestLevel = INT_MIN;
        // for(int i = 0; i < levelOrder.size(); i++)
        // {
        //     // for(int j = 0; j < levelOrder[i].size(); j++)
        //     //     LOG1(levelOrder[i][j]);
        //     // LOG2("");
        //     int j, k;
        //     for(j = 0; j < levelOrder[i].size(); j++)
        //         if(levelOrder[i][j] != INT_MAX)
        //             break;
                    
        //     for(k = levelOrder[i].size() - 1; k >= 0; k--)
        //         if(levelOrder[i][k] != INT_MAX)
        //             break;
                    
        //     longestLevel = max(longestLevel, k-j+1);
        // }
        // return longestLevel;
        
        // dfs
        // int longestLevel = INT_MIN;
        // vector<int> lefts;
        // recur(root, 0, 0, longestLevel, lefts);
        // return longestLevel;
        
        // bfs
        if(root == NULL)
            return 0;
        int longestLevel = INT_MIN;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 0));
        
        while(!q.empty())
        {
            int left = q.front().second;
            int right = left;
            int oldSize = q.size();
            // oldSize takes care of the current depth of traversal
            for(int i = 0; i < oldSize; ++i)
            {
                TreeNode* temp = q.front().first;
                right = q.front().second;
                q.pop();
                if(temp->left)
                    q.push(pair<TreeNode*, int>(temp->left, 2*right));
                if(temp->right)
                    q.push(pair<TreeNode*, int>(temp->right, 2*right + 1));
            }
            longestLevel = max(longestLevel, right - left + 1);
        }
        
        return longestLevel;
    }
};

int main()
{
    Solution s;
    
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(1);
    head->left->left = new TreeNode(1);
    head->left->left->left = new TreeNode(1);
    head->right = new TreeNode(1);
    head->right->right = new TreeNode(1);
    head->right->right->right = new TreeNode(1);
    
    LOG2(s.widthOfBinaryTree(head));
    return 0;
}