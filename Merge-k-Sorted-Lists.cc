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

class Comp
{
public:
    bool operator ()(pair<int, ListNode*> P, pair<int, ListNode*> Q)
    {
        return P.first > Q.first;
    }
};

class Solution 
{
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        // recurcive
        // if(l1 == NULL)
        //     return l2;
            
        // if(l2 == NULL)
        //     return l1;
            
        // if(l1->val < l2->val)
        // {
        //     l1->next = merge2Lists(l1->next, l2);
        //     return l1;
        // }
        
        // else
        // {
        //     l2->next = merge2Lists(l1, l2->next);
        //     return l2;
        // }
        //
        
        // iterative
        ListNode* mergedHead = new ListNode(0);
        ListNode* ptr = mergedHead;
        while(l1 || l2)
        {
            if(l1 == NULL)
            {
                ptr->next = l2;
                break;
            }
            
            if(l2 == NULL)
            {
                ptr->next = l1;
                break;
            }
                
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                ptr = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                ptr = l2;
                l2 = l2->next;
            }
        }
        return mergedHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // naive
        // vector<int> temp;
        // for(auto list : lists)
        // {
        //     while(list != NULL)
        //     {
        //         temp.push_back(list->val);
        //         list = list->next;
        //     }
        // }
        // sort(temp.begin(), temp.end());
        
        // ListNode* mergedHead = new ListNode(0);
        // ListNode* ptr = mergedHead;
        // for(int i:temp)
        // {
        //     ListNode* t = new ListNode(i);
        //     ptr->next = t;
        //     ptr = t;
        // }
        // return mergedHead->next;
        //
        
        // won't work; wrong solution
        // priority_queue<int, vector<int>, greater<int>> pq;
        // ListNode* mergedHead = new ListNode(0);
        // ListNode* ptr = mergedHead;
        // int countAllNULL = 0;
        // for(int i = 0; i < lists.size(); i++)
        // {
        //     if(lists[i] != NULL)
        //     {
        //         pq.push(list[i]->val);
        //         list[i] = list[i]->next;
        //     }
        //     else
        //         countAllNULL++;
                
        //     if(countAllNULL == list.size())
        //         break;
                
        //     else if(i == lists.size()-1)
        //     {
        //         while(!pq.empty())
        //         {
        //             ListNode* t = new ListNode(pq.top());
        //             pq.pop();
        //             ptr->next = t;
        //             ptr = t;
        //         }
        //         i = 0;
        //     }
            
        //     else if(countAllNULL == list.size())
        //         break;
        // }
        // return mergedHead->next;
        //
        
        // using priority queue
        // priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Comp> pq;
        // ListNode* mergedHead = new ListNode(0);
        // ListNode* ptr = mergedHead;
        
        // for(auto list:lists)
        //     if(list)
        //         pq.push(make_pair(list->val, list));
                
        // while(!pq.empty())
        // {
        //     ListNode* temp = pq.top().second;
        //     temp = temp->next;
            
        //     ListNode* t = new ListNode(pq.top().first);
        //     pq.pop();
        //     ptr->next = t;
        //     ptr = t;
            
        //     if(temp)
        //         pq.push(make_pair(temp->val, temp));
        // }
        // return mergedHead->next;
        //
        
        // merge 2 list
        if(lists.size() == 0)
            return NULL;
        while(lists.size() > 1)
        {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin(), lists.begin()+2);
        }
        return lists[0];
    }
};

int main()
{
    Solution s;
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(8);
    
    ListNode* head3 = new ListNode(3);
    head3->next = new ListNode(9);
    head3->next->next = new ListNode(27);
    
    vector<ListNode*> lists = {head1, head2, head3};
    ListNode* ans = s.mergeKLists(lists);
    
    while(ans)
    {
        LOG2(ans->val);
        ans = ans->next;
    }
    
    return 0;
}