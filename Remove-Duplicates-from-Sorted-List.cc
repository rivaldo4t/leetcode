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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        ListNode* ptr1 = head, *ptr2 = head->next;
        int lastVal = ptr1->val;
        
        while(ptr2 != NULL)
        {
            if(ptr2->val != lastVal)
            {
                ptr1 = ptr1->next;
                ptr1->val = ptr2->val;
                lastVal = ptr2->val;
            }
            ptr2 = ptr2->next;
        }
        ptr1->next = NULL;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    // head-> next = new ListNode(1);
    // head-> next-> next = new ListNode(1);
    // head-> next-> next-> next = new ListNode(3);
    // head-> next-> next-> next-> next = new ListNode(3);
    // head-> next-> next-> next-> next-> next = new ListNode(5);
    
    auto temp = s.deleteDuplicates(head);
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}