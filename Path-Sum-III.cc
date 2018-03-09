#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution 
// {
// public:

//     void recur(TreeNode* root, int sum, vector<int>& temp, int& count)
//     {
//         if(root == NULL)
//             return;

//         temp.push_back(root->val);
//         recur(root->left, sum, temp, count);
//         recur(root->right, sum, temp, count);
        
//         int tempSum = 0;
//         for(int i = temp.size()-1; i >= 0; i--)
//         {
//             tempSum += temp[i];
            
//             if(tempSum == sum)
//                 count++;
//         }
//         temp.pop_back();
//     }

//     int pathSum(TreeNode* root, int sum) 
//     {
//         vector<int> temp;
//         int count = 0;
//         recur(root, sum, temp, count);
//         return count;
//     }
// };

class Solution {
    unordered_map<int, int> mp;
    int ans, tar;
    void dfs(TreeNode * p, int s)
    {
        s += p->val;
        // if (mp.count(s - tar))
            ans += mp[s - tar];

        mp[s]++;
        
        if (p->left)
            dfs(p->left, s);
            
        if (p->right)
            dfs(p->right, s);
        
        mp[s]--;
        // s -= p->val;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        tar = sum;
        ans = 0;
        mp[0] = 1;
        dfs(root, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(10);
    head->right = new TreeNode(-3);
    head->right->right = new TreeNode(11);
    head->left = new TreeNode(5);
    head->left->right = new TreeNode(2);
    head->left->right->right = new TreeNode(1);
    head->left->left = new TreeNode(3);
    head->left->left->right = new TreeNode(-2);
    head->left->left->left = new TreeNode(3);
    
    cout << s.pathSum(head, 8) << endl;
    
    return 0;
}