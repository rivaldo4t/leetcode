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
    int maxSum;
    int recur(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left = max(0, recur(root->left));
        int right = max(0, recur(root->right));
        
        // check if considering this node in path gives greater sum than maxSum
        maxSum = max(maxSum, left + root->val + right);
        
        // bottom up - after updating maxSum from bottom till this node,
        // return the path along this node that yields maximum sum to consider
        // in any path consisting of parent of this node
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) 
    {
        maxSum = INT_MIN;
        recur(root);
        return maxSum == INT_MIN ? 0 : maxSum;
    }
};

int main()
{
    Solution s;
    TreeNode* head1 = new TreeNode(4);
    head1->left = new TreeNode(1);
    head1->left->left = new TreeNode(2);
    head1->left->left->left = new TreeNode(3);
    
    LOG2(s.maxPathSum(head1));
    return 0;
}