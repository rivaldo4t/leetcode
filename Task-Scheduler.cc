#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
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
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> map(26, 0);
        for(auto i:tasks)
            map[i-'A']++;
        
        priority_queue<int> q;
        for(auto i:map)
            if(i > 0)
                q.push(i);
        
        int totalTime = 0;
        while(!q.empty())
        {
            int i = 0;
            list<int> temp;
            // start cooldown
            while(i <= n)
            {
                if(!q.empty())
                {
                    if(q.top() > 1)
                        temp.push_back(q.top() - 1);
                    q.pop();
                }
                totalTime++;
                if(q.empty() && temp.empty())
                    break;
                i++;
            }
            // cooldown elapsed for the most frequent task
            for(auto i: temp)
                q.push(i);
        }
        
        return totalTime;
    }
};


int main()
{
    Solution s;
    std::vector<char> tasks = {'A', 'B', 'C', 'B', 'A', 'B'};
    LOG2(s.leastInterval(tasks, 2));
    return 0;
}