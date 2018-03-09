#include <iostream>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(head == NULL)
            return head;
        if(m >= n)
            return head;
        
        ListNode *p, *q, *r, *temp, *left;
        q = NULL, r = NULL, temp = NULL;
        p = head;
        int count = 1;
        
        while(count<m)
        {
            q = p;
            p = p->next;
            count++;
        }
        
        r = p->next;
        left = p;
        
        while(count<n)
        {
            temp = r->next;
            r->next = p;
            p = r;
            r = temp;
            count++;
        }
        
        left->next = r;
        if(q == NULL)
            head = p;
        else
            q->next = p;
        
        return head;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head-> next = new ListNode(2);
    head-> next-> next = new ListNode(3);
    head-> next-> next-> next = new ListNode(4);
    head-> next-> next-> next-> next = new ListNode(5);
    head-> next-> next-> next-> next-> next = new ListNode(6);
    ListNode* temp = s.reverseBetween(head, 1, 6);
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}