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

struct RandomListNode 
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(head == NULL)
            return head;
            
        // O(N) space
        // RandomListNode* newHead = new RandomListNode(head->label);
        // RandomListNode* ptr = head;
        // RandomListNode* ptr2 = newHead;
        // while(ptr->next)
        // {
        //     ptr2->next = new RandomListNode(ptr->next->label);
        //     ptr = ptr->next;
        //     ptr2 = ptr2->next;
        // }
        
        // // save original list
        // map<RandomListNode*, RandomListNode*> storeNext;
        // ptr = head;
        // while(ptr)
        // {
        //     storeNext[ptr] = ptr->next;
        //     ptr = ptr->next;
        // }
        
        // // modify next
        // ptr = head;
        // ptr2 = newHead;
        // while(ptr)
        // {
        //     RandomListNode* temp = ptr->next;
        //     ptr->next = ptr2;
        //     ptr2->random = ptr;
        //     ptr = temp;
        //     ptr2 = ptr2->next;
        // }
        
        // // modify random
        // ptr2 = newHead;
        // while(ptr2)
        // {
        //     ptr2->random =  ptr2->random->random ? 
        //                     ptr2->random->random->next : 
        //                     ptr2->random->random;
        //     ptr2 = ptr2->next;
        // }
        
        // // restore original
        // for(auto temp:storeNext)
        //     temp.first->next = temp.second;    
        
        // return newHead;
        
        // O(1)
        RandomListNode* ptr = head;
        while(ptr)
        {
            RandomListNode* temp = ptr->next;
            ptr->next = new RandomListNode(ptr->label);
            ptr->next->next = temp;
            ptr = temp;
        }
        
        ptr = head;
        while(ptr)
        {
            if(ptr->random)
                ptr->next->random = ptr->random->next;
            ptr = ptr->next ? ptr->next->next : ptr->next;
        }
        
        RandomListNode* newHead = head->next;
        RandomListNode* ptr2 = newHead;
        ptr = head;
        while(ptr && ptr2)
        {
            ptr->next = ptr->next ? ptr->next->next : ptr->next;
            ptr2->next = ptr2->next ? ptr2->next->next : ptr2->next;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        
        return newHead;
    }
};

int main()
{
    Solution s;
    return 0;
}