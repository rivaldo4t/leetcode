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
    TreeNode* recur1(ListNode* head, ListNode* tail)
    {
        if(head == tail)
            return NULL;
            
        ListNode* slow = head, *fast = head;
        while(fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = recur1(head, slow);
        root->right = recur1(slow->next, tail);
        return root;
    }
    
    TreeNode* recur2(ListNode* &head, int low, int high)
    {
        if(low > high)
            return NULL;
            
        int mid = low + (high-low)/2;
        TreeNode* left = recur2(head, low, mid-1);
        
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        
        head = head->next;
        
        root->right = recur2(head, mid+1, high);
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        // crude solution
        // ListNode* slow = head, *fast = head;
        // TreeNode* root = NULL, *prev = NULL;
        
        // if(head == NULL)
        //     return root;
            
        // else if (head->next == NULL)
        // {
        //     root = new TreeNode(head->val);
        //     return root;
        // }
        
        // while(fast && fast->next)
        // {
        //     TreeNode* ptr = new TreeNode(slow->val);
        //     ptr->left = prev;
        //     prev = ptr;
            
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // TreeNode* ptr = new TreeNode(slow->val);
        // ptr->left = prev;
        // prev = ptr;
        
        // root = prev;
        
        // slow = slow->next;
        // while(slow)
        // {
        //     TreeNode* ptr = new TreeNode(slow->val);
        //     prev->right = ptr;
        //     prev = ptr;
            
        //     slow = slow->next;
        // }
        // return root;
        
        // recursive1
        // return recur1(head, NULL);
        
        // recursive2
        if(head == NULL)
            return NULL;
        int size = 0;
        ListNode* ptr = head;
        while(ptr)
        {
            size++;
            ptr = ptr->next;
        }
        return recur2(head, 0, size-1);
    }
};

int main()
{
    Solution s;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    TreeNode* root = s.sortedListToBST(head);
    LOG2(root->val);
    
    return 0;
}