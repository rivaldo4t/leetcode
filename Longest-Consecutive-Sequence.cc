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
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> set;
        for(auto i:nums)
            set.insert(i);
        
        int maxLen = 0;
        int currLen = 0, curr;
        
        for(auto i:nums)
        {
            if(set.find(i-1) == set.end())
            {
                curr = i;
                currLen = 1;
                while(set.find(curr+1) != set.end())
                {
                    curr++;
                    currLen++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        
        return maxLen;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    LOG2(s.longestConsecutive(nums));
    return 0;
}