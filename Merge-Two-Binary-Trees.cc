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
    void recur(TreeNode* t1, TreeNode* t2, TreeNode*& t3)
    {
        if(t1 == NULL && t2 == NULL)
            return;
        
        int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        LOG2(val);
        t3 = new TreeNode(val);
        
        TreeNode* left = NULL, *right = NULL;
        recur(t1 ? t1->left : NULL, t2 ? t2->left : NULL, left);
        recur(t1 ? t1->right : NULL, t2 ? t2->right : NULL, right);
        
        t3->left = left;
        t3->right = right;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        TreeNode* t3 = NULL;
        recur(t1, t2, t3);
        return t3;
    }
};

int main()
{
    Solution s;
    TreeNode* head1 = new TreeNode(1);
    head1->left = new TreeNode(3);
    head1->right = new TreeNode(2);
    head1->left->left = new TreeNode(5);
    
    TreeNode* head2 = new TreeNode(2);
    head2->left = new TreeNode(1);
    head2->right = new TreeNode(3);
    head2->left->right = new TreeNode(4);
    head2->right->right = new TreeNode(7);

    TreeNode* head3 = s.mergeTrees(head1, head2);
    // LOG2(head3->left->val);
    return 0;
}