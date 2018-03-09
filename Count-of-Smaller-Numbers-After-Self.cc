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
#include <iterator>
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
    vector<int> countSmaller(vector<int>& nums) 
    {
        multiset<int> s;
        vector<int> ans(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; --i)
        {
            s.insert(nums[i]);
            // LOG1(*(s.begin()));
            // LOG1(*(s.find(nums[i])));
            // auto it = s.find(nums[i]);
            multiset<int>::iterator it = s.find(nums[i]);
            // ++it;
            // int c = it - s.begin();
            // LOG2(c);
            // vector<int> temp (s.begin(), it);
            // LOG2(temp.size());
            // for(auto j = s.begin(); j != s.find(nums[i]); ++j)
            //     LOG1(*j);
            // LOG2("");
            // ans[i] = temp.size()-1;
            ans[i] = distance(s.begin(), it);
            // ans[i] = distance(it, s.begin())-1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 2, 6, 1, 7, 1, 8};
    vector<int> ans = s.countSmaller(nums);
    for(auto i:ans)
        LOG2(i);
    return 0;
}