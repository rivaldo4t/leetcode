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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* r = head;
        ListNode* p = head;
        ListNode* q = head;
        while(n--)
        {
            q = q->next;
        }
        if(q == NULL)
        {
            //case of first node deletion
            r = head->next;
            head->next = NULL;
            delete(head);
            head = r;
        }
        else
        {
            while(q->next!=NULL)
            {
                p = p->next;
                q = q->next;
            }
            ListNode* s = p->next->next;
            p->next->next = NULL;
            delete(p->next);
            p->next = s;
        }
        
        return r;
    }
};

int main()
{
    Solution s;
    ListNode* start = new ListNode(1);
    start-> next = new ListNode(2);
    start-> next-> next = new ListNode(3);
    start-> next-> next-> next = new ListNode(4);
    start-> next-> next-> next-> next = new ListNode(5);
    ListNode* temp = s.removeNthFromEnd(start, 5);
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}