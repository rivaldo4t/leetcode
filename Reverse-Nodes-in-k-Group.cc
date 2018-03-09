#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <queue>
#include <list>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
    ListNode* recur(ListNode* head, int k)
    {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        int count = k;
        
        while(curr && count--)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if(next != NULL)
            head->next = reverseKGroup(next, k);
            
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        if(count < k)
            return head;
        return recur(head, k);
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
    
    ListNode* temp = s.reverseKGroup(head, 7);
    while(temp!=NULL)
    {
        LOG1(temp->val);
        temp = temp->next;
    }
    LOG2("");
    return 0;
}