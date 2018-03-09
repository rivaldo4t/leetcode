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
    int findPeakElement(vector<int>& nums) 
    {
        // since we can find any peak, binary search works to give logN solution
        int low = 0, high = nums.size()-1;
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] < nums[mid+1]) // mid is on a rising slope from left
                low = mid + 1;
            else    // mid is on rising slope from right
                high = mid;
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    LOG2(s.findPeakElement(nums));
    return 0;
}