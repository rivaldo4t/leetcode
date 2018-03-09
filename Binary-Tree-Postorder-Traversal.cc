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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        stack<pair<TreeNode*, bool>> stk;
        stk.push({root, false});
        
        while(!stk.empty())
        {
            TreeNode* temp = stk.top().first;
            bool processed = stk.top().second;
            if(!processed)
            {
                stk.top().second = true;
                if(temp->right)
                    stk.push({temp->right, false});
                if(temp->left)
                    stk.push({temp->left, false});
            }
            else
            {
                ans.push_back(stk.top().first->val);
                stk.pop();
            }
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
    head1->right->left = new TreeNode(5);
    vector<int> ans = s.postorderTraversal(head1);
    for(auto i:ans)
        LOG2(i);
    return 0;
}