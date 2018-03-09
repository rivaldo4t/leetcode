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
    // O(N^2); takes too long
    unordered_set<TreeNode*> ans;
    unordered_map<string, TreeNode*> mp;
    
    string dfs(TreeNode* root)
    {
        if(root == NULL)
            return "#";
        return to_string(root->val) + "," + dfs(root->left) +  "," + dfs(root->right);
    }
    
    void recur(TreeNode* root)
    {
        if(root == NULL)
            return;
            
        string str = dfs(root);
        LOG2(str);
        if(mp.count(str) == 0)
            mp[str] = root;
        else
            ans.insert(mp[str]);
            
        recur(root->left);
        recur(root->right);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        if(root == NULL)
            return vector<TreeNode*> {};
        ans.clear();
        mp.clear();
        recur(root);
        vector<TreeNode*> res;
        for(auto i:ans)
            res.push_back(i);
        return res;
    }
};

int main()
{
    Solution s;
    
    // TreeNode *head = new TreeNode(1);
    // head->left = new TreeNode(2);
    // head->left->left = new TreeNode(4);
    // head->left->right = new TreeNode(5);
    // head->right = new TreeNode(3);
    // head->right->right = new TreeNode(2);
    // head->right->right->left = new TreeNode(4);
    // head->right->right->right = new TreeNode(5);
    
    // TreeNode *head = new TreeNode(1);
    // head->left = new TreeNode(2);
    // head->left->left = new TreeNode(4);
    // head->right = new TreeNode(3);
    // head->right->right = new TreeNode(2);
    // head->right->right->right = new TreeNode(4);
    
    TreeNode *head = new TreeNode(0);
    head->left = new TreeNode(0);
    head->left->left = new TreeNode(0);
    head->right = new TreeNode(0);
    head->right->right = new TreeNode(0);
    head->right->right->right = new TreeNode(0);
    
    vector<TreeNode*> ans = s.findDuplicateSubtrees(head);
    
    return 0;
}