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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *prev, *curr, *temp;
        prev = NULL;
        curr = head;
        
        while(curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
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
    start-> next-> next-> next-> next = new ListNode(5);
    ListNode* temp = s.reverseList(start);
    while(temp!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}