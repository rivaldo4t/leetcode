#include <iostream>
#include <vector>
#include <stack>
#include <climits>
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
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> stk;
        TreeNode* ptr = root;
        while(ptr != NULL || !stk.empty())
        {
            while(ptr!=NULL)
            {
                stk.push(ptr);
                ptr = ptr->left;
            }
            ptr = stk.top();
            stk.pop();
            k--;
            cout << k << endl;
            if(k == 0)
                return ptr->val;
            ptr = ptr->right;
        }
        if(k!=0)
            return INT_MIN;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(50);
    head->left = new TreeNode(40);
    head->left->left = new TreeNode(20);
    head->left->right = new TreeNode(45);
    head->right = new TreeNode(60);
    head->right->left = new TreeNode(55);
    head->right->right = new TreeNode(70);
    cout << s.kthSmallest(head, 4) << endl;
    return 0;
}