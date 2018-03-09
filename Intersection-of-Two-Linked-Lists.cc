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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* ptr, *ptr2;
        ptr = headA;
        ptr2 = headB;
        int count = 0;
        /*
        while(1)
        {
            if(count >=2 )
                return NULL;
            if(ptr == NULL || ptr2 == NULL)
                count++;
            if(ptr == NULL)
                ptr = headB;
            if(ptr2 == NULL)
                ptr2 = headA;
            if(ptr == ptr2)
                return ptr;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        */
        while(ptr != ptr2)
        {
            ptr = ptr == NULL?headB:ptr->next;
            ptr2 = ptr2 == NULL?headA:ptr2->next;
        }
        return ptr;
    }
};

int main()
{
    Solution s;
    ListNode* list1 = new ListNode(1);
    list1-> next = new ListNode(2);
    list1-> next-> next = new ListNode(3);
    list1-> next-> next-> next = new ListNode(4);
    list1-> next-> next-> next-> next = new ListNode(5);
    list1-> next-> next-> next-> next-> next = new ListNode(6);
    
    ListNode* list2 = new ListNode(7);
    list2-> next = new ListNode(8);
    //list2-> next-> next = list1-> next-> next-> next-> next;
    
    ListNode* temp = s.getIntersectionNode(list1, list2);
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}