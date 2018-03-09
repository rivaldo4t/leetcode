#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:

    ListNode* recur(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* p = recur(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL)
            return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = recur(slow->next);
        ListNode* begin = head;
        while(begin != slow)
        {
            if(begin->val != newhead->val)
                return false;
            
            begin = begin->next;
            newhead = newhead->next;
        }
        if(newhead != NULL && begin->val != newhead->val)
            return false;
        return true;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head-> next = new ListNode(2);
    head-> next-> next = new ListNode(3);
    head-> next-> next-> next = new ListNode(3);
    head-> next-> next-> next-> next = new ListNode(1);
    // head-> next-> next-> next-> next-> next = new ListNode(1);
    
    cout << s.isPalindrome(head) << endl;
    
    return 0;
}