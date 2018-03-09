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
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode* temp = stk.top();
            stk.pop();
            if(temp->right)
                stk.push(temp->right);
            if(temp->left)
                stk.push(temp->left);
            ans.push_back(temp->val);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    TreeNode* head1 = new TreeNode(1);
    head1->left = new TreeNode(3);
    head1->right = new TreeNode(2);
    head1->left->left = new TreeNode(5);
    vector<int> ans = s.preorderTraversal(head1);
    for(auto i:ans)
        LOG2(i);
    return 0;
}