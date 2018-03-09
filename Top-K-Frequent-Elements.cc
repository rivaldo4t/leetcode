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
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
     
        vector<int> ans;
        
        // using priority_queue
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // for(auto i:mp)
        // {
        //     pq.push(make_pair(i.second, i.first));
        //     while(pq.size() > k)
        //         pq.pop();
        // }
        // while(!pq.empty())
        // {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;
        
        vector<vector<int>> bucket(nums.size()+1);
        for(auto i:mp)
            bucket[i.second].push_back(i.first);
            
        for(int i = bucket.size()-1; i >= 0; --i)
        {
            for(int j = 0; j < bucket[i].size(); ++j)
            {
                ans.push_back(bucket[i][j]);
                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 5, 3, 2, 4, 3, 3};
    vector<int> ans = s.topKFrequent(nums , 2);
    for(auto i:ans)
        LOG2(i);
    return 0;
}