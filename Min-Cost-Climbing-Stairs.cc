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
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl

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
    int minCostClimbingStairs(std::vector<int>& cost) 
    {
        std::vector<int> minCost(cost.size()+1, 0);
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        
        int i;
        for(i = 0; i < cost.size(); i++)
        {
            minCost[i] = cost[i] + std::min(minCost[i-1], minCost[i-2]);
        }
        minCost[i] = std::min(minCost[i-1], minCost[i-2]);
        
        return minCost[minCost.size()-1];
    }
};

int main()
{
    Solution s;
    LOG2(s.minCostClimbingStairs(*(new std::vector<int> {1, 100, 1, 1, 1, 100, 1, 1, 100, 1})));
    return 0;
}