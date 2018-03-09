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
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        // recursive
        // if(head == NULL)
        //     return head;
            
        // if(head->next != NULL && head->val == head->next->val)
        // {
        //     while(head->next != NULL && head->val == head->next->val)
        //         head = head->next;
            
        //     return deleteDuplicates(head->next);
        // }
        // else
        //     head->next = deleteDuplicates(head->next);
            
        // return head;
        
        // iterative
        if(head == NULL)
            return head;
            
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        
        while(fast)
        {
            while(fast->next != NULL && fast->val == fast->next->val)
                fast = fast->next;
                
            if(slow->next == fast)
                slow = fast;
                
            else
                slow->next = fast->next;
            
            fast = fast->next;
        }
        
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(4);
    
    ListNode* newHead = s.deleteDuplicates(head);
    while(newHead)
    {
        LOG1(newHead->val);
        newHead = newHead->next;
    }
    LOG2("");
    return 0;
}