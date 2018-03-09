#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl

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
    // TLE; accepted without map
//     std::unordered_map<TreeNode*, int> valMap;
//     int recur(TreeNode* root)
//     {
//         if(root == NULL)
//             return 0;
            
//         if(valMap.find(root) != valMap.end())
//             return valMap[root];
        
//         int loot = 0;
        
//         if(root->left)
//             loot += rob(root->left->left) + rob(root->left->right); 
//         if(root->right)
//             loot += rob(root->right->left) + rob(root->right->right); 
            
//         loot = std::max(loot + root->val, rob(root->left) + rob(root->right));
//         valMap.insert({root, loot});
//         return loot;
//     }
// public:
//     int rob(TreeNode* root) 
//     {
//         valMap.clear();
//         return recur(root);   
//     }
    std::vector<int> recur(TreeNode* root)
    {
        if(root == NULL)
            return (*new std::vector<int> (2, 0));
            
        std::vector<int> left = recur(root->left);
        std::vector<int> right = recur(root->right);
        
        std::vector<int> res;
        res.push_back(std::max(left[0], left[1]) + std::max(right[0], right[1]));
        res.push_back(root->val + left[0] + right[0]);
        return res;
    }
public:
    int rob(TreeNode* root) 
    {
        std::vector<int> res = recur(root);
        return std::max(res[0], res[1]);
    }

};

int main()
{
    Solution s;
    TreeNode* head1 = new TreeNode(4);
    head1->left = new TreeNode(1);
    head1->left->left = new TreeNode(2);
    head1->left->left->left = new TreeNode(3);
    LOG2(s.rob(head1));
    return 0;
}