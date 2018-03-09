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
    int deleteAndEarn(vector<int>& nums) 
    {
        
        // See house robber
        
        vector<int> count(10001, 0);
        for(int i:nums)
            count[i]++;
            
        int inc = 0, exc = 0, prev = -1;
        for(int i = 1; i <= 10000; i++)
        {
            if(count[i] > 0)
            {
                int temp = max(inc, exc);
                if(i-1 != prev)
                    inc = i * count[i] + temp;
                else
                    inc = i * count[i] + exc;
                exc = temp;
                prev = i;   
            }
        }
        
        return max(inc, exc);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,2,3,3,3,4};
    LOG2(s.deleteAndEarn(nums));
    return 0;
}