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
    ListNode* detectCycle(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        
        ListNode *ptr1, *ptr2;
        ptr1 = head;
        ptr2 = head;
        while(ptr1->next != NULL && ptr2->next != NULL && ptr2->next->next != NULL)
        {
            cout << ptr1->val << endl;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2)
            {
                ptr1 = head;
                while(ptr1 != ptr2)
                {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1;
            }
        }
        return NULL;
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
    //head-> next-> next-> next-> next-> next->next = head-> next-> next-> next;
    
    ListNode* temp = s.detectCycle(head);
    //cout << temp->val;
    /*
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    */
    return 0;
}