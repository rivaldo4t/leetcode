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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL)
            return head;
            
        ListNode** prev = &head;
        ListNode* p = head;
        
        if(head->next == NULL)
            return head;
        
        ListNode* q = head->next;
        
        while(q!= NULL)
        {
            p->next = q->next;
            q->next = p;
            *prev = q;
            
            if(p->next == NULL || p->next->next == NULL)
                break;
                
            prev = &(p->next);
            q = p->next->next;
            p = p->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode* start = new ListNode(1);
    start-> next = new ListNode(2);
    start-> next-> next = new ListNode(3);
    start-> next-> next-> next = new ListNode(4);
    start-> next-> next-> next->next = new ListNode(5);
    start-> next-> next-> next->next->next = new ListNode(6);
    ListNode* temp = s.swapPairs(start);
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}