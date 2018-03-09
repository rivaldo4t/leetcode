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

struct TreeLinkNode 
{
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution 
{
    void recur(TreeLinkNode* root, TreeLinkNode* leftChild, TreeLinkNode* rightChild)
    {
        if(root == NULL || (leftChild == NULL && rightChild == NULL))
            return;
        
        leftChild->next = rightChild;
        if(root->next == NULL)
            rightChild->next = NULL;
        else
            rightChild->next = root->next->left;
            
        recur(leftChild, leftChild->left, leftChild->right);
        recur(rightChild, rightChild->left, rightChild->right);
    }
public:
    void connect(TreeLinkNode *root) 
    {
        if(root == NULL)
            return;
        
        // recursive
        // recur(root, root->left, root->right);
        
        // iterative
        TreeLinkNode* temp;
        
        while(root->left)
        {
            temp = root;
            while(temp)
            {
                temp->left->next = temp->right;
                if(temp->next)
                    temp->right->next = temp->next->left;
                temp = temp->next;
            }
            root = root->left;
        }
    }
};

int main()
{
    Solution s;
    
    TreeLinkNode *head = new TreeLinkNode(1);
    head->left = new TreeLinkNode(2);
    head->right = new TreeLinkNode(3);
    
    s.connect(head);
    LOG2(head->left->next->val);
    
    return 0;
}