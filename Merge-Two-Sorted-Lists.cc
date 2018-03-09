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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode *retList;
        
        if(l1->val < l2->val)
        {
            retList = l1;
            ptr1 = ptr1->next;
        }
        else
        {
            retList = l2;
            ptr2 = ptr2->next;
        }
        
        ListNode *curr = retList;
        while(ptr1 || ptr2)
        {
            if(!ptr1)
            {
                curr->next = ptr2;
                return retList;
            }
            else if(!ptr2)
            {
                curr->next = ptr1;
                return retList;
            }
            else if(ptr1->val < ptr2->val)
            {
                curr->next = ptr1;
                curr = curr->next;
                ptr1 = ptr1->next;
            }
            else
            {
                curr->next = ptr2;
                curr = curr->next;
                ptr2 = ptr2->next;
            }
        }
        
        return retList;
    }
};

int main()
{
    Solution s;
    
    ListNode* list1 = new ListNode(1);
    list1-> next = new ListNode(5);
    list1-> next-> next = new ListNode(8);
    
    ListNode* list2 = new ListNode(2);
    list2-> next = new ListNode(3);
    list2-> next-> next = new ListNode(7);
    list2-> next-> next->next = new ListNode(9);
    
    ListNode* list = s.mergeTwoLists(list1, list2);
    ListNode* temp = list;
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}