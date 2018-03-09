#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// previous attempt at qsort
#if 0
class Solution 
{
    void swapData(ListNode* p1, ListNode* p2)
    {
        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;
    }
    
    ListNode* getTail(ListNode* head)
    {
        while(head != NULL && head->next != NULL)
            head = head->next;
        return head;
    }
    
    ListNode* partition(ListNode* p1, ListNode* p2)
    {
        ListNode* pivot = p2;
        ListNode* swapper = NULL;
        
        for(ListNode* i = p1; i != p2; i = i->next)
        {
            if(i->val <= pivot->val)
            {
                if(swapper == NULL)
                    swapper = p1;
                else
                    swapper = swapper->next;
                swapData(swapper, i);
            }
        }
        
        if(swapper == NULL)
        {
            swapper = p1;
            swapData(swapper, pivot);
            return swapper;
        }
        else
        {
            swapData(swapper->next, pivot);
            return swapper->next;
        }
    }
    
    ListNode* listQsort(ListNode* p1, ListNode* p2)
    {
        if(p1 != p2)
        {
            ListNode* part = partition(p1, p2), *firstHalf = NULL, *secondHalf = NULL;
            
            ListNode* temp = p1;
            if(temp == part)
                firstHalf = temp;
            else
            {
                while(temp->next != part)
                    temp = temp->next;
            }
            temp->next = NULL;
            
            firstHalf = firstHalf == NULL ? listQsort(p1, temp) : firstHalf;
            secondHalf = listQsort(part->next, p2);
            
            while(firstHalf->next != NULL)
                firstHalf = firstHalf->next;
            if(firstHalf != part)
                firstHalf->next = part;
            part->next = secondHalf;
        }
        
        return p1;
    }
public:
    ListNode* sortList(ListNode* head) 
    {
        ListNode* tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        listQsort(head, tail);
    }
};
#endif

// Merge Sort
class Solution
{
// recursive
#if 0
    ListNode* mergeSortedLists(ListNode* a, ListNode* b)
    {
        if(!a && !b)
            return NULL;
        if(!a)
            return b;
        if(!b)
            return a;
        
        ListNode* temp = NULL;
        if(a->val <= b->val)
        {
            temp = a;
            temp->next = mergeSortedLists(a->next, b);
        }
        else
        {
            temp = b;
            temp->next = mergeSortedLists(a, b->next);
        }
        return temp;
    }
#endif
// iterative
    ListNode* mergeSortedLists(ListNode* a, ListNode* b)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        ListNode* temp = NULL;
        
        if(a == NULL && b == NULL)
            return dummy->next;
            
        while(1)
        {
            if(a == NULL)
            {
                ptr->next = b;
                break;
            }
            else if(b == NULL)
            {
                ptr->next = a;
                break;
            }
            else if(a->val <= b->val)
            {
                temp = a;
                a = a->next;
                temp->next = ptr->next;
                ptr->next = temp;
            }
            else
            {
                temp = b;
                b = b->next;
                temp->next = ptr->next;
                ptr->next = temp;
            }
            ptr = ptr->next;
        }
        return dummy->next;
    }
    
    void splitList(ListNode* head, ListNode*& a, ListNode*& b)
    {
        ListNode* fast = head, *slow = head, *prev = NULL;
        if (head == NULL || head->next == NULL)
        {
            a = head;
            b = NULL;
        }
        
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        a = head;
        prev->next = NULL;
        b = slow;
    }
    
public:
    ListNode* sortList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *a, *b;
        
        splitList(head, a, b);
        
        a = sortList(a);
        b = sortList(b);
        
        return mergeSortedLists(a, b);
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(23);
    head->next = new ListNode(12);
    head->next->next = new ListNode(62);
    head->next->next->next = new ListNode(11);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(51);
    head->next->next->next->next->next->next = new ListNode(9);
    
    ListNode* sorted = s.sortList(head);
    
    while(sorted != NULL)
    {
        LOG2(sorted->val);
        sorted = sorted->next;
    }
    
    return 0;
}