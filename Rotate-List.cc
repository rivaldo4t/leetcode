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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == 0 || k == 0)
            return head;
            
        int n = 0;
        ListNode* ptr = head;
        while(ptr)
        {
            ptr = ptr->next;
            n++;
        }
        k %= n;
     
        if(k == 0)
            return head;
        
        // below code was written so that size of linked list is not calculated
        ListNode *slow = head, *prevSlow = NULL, *fast = head, *prevFast = NULL;
        while(k--)
        {
            // if(fast == NULL)
            //     fast = head;
            fast = fast->next;
        }
        
        
        // if(fast == NULL)
        //     return head;
        
        while(fast)
        {
            prevSlow = slow;
            slow = slow->next;
            prevFast = fast;
            fast = fast->next;
        }
        
        prevFast->next = head;
        prevSlow->next = NULL;
        return slow;
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
    
    ListNode* newHead = s.rotateRight(head, 201);
    while(newHead)
    {
        LOG2(newHead->val);
        newHead = newHead->next;
    }
    return 0;
}