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
    int threeSumClosest(vector<int>& nums, int target) 
    {
        long int closestSum = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            int temp;
            int low = i+1, high = nums.size()-1;
            while(low < high)
            {
                temp = nums[i] + nums[low] + nums[high];
                
                if(temp == target)
                    return target;

                if(temp < target)
                    low++;
                else
                    high--;
                    
                closestSum = abs(closestSum - target) < abs(temp - target) ? closestSum : temp;
            }
            // LOG2(temp);
            // LOG2(closestSum);
            // LOG2("");
        }
        return closestSum;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {-1, 2, 1, -4};
    // vector<int> nums = {1,1,-1,-1,3};
    vector<int> nums = {1,2,5,10,11};
    LOG2(s.threeSumClosest(nums, 12));
    return 0;
}