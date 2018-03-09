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

class pairComparator
{
    // lulz
    bool lexOrder(string a, string b)
    {
        bool temp;
        int i = 0;
        
        while(i < a.size() && i < b.size())
        {
            if(a[i] < b[i])
                return true;
            else if(a[i] > b[i])
                return false;
            else
                i++;
        }
        return i == a.size() ? true : false;
    }
 public:
    bool operator ()(pair<string, int> a, pair<string, int> b)
    {
        return a.second > b.second ||
                a.second == b.second && lexOrder(a.first, b.first);
                // turns out simple a.first < b.first would have sufficed
    }
    
    bool operator ()(pair<int, string> a, pair<int, string> b)
    {
        return a.first < b.first ||
                a.first == b.first && a.second > b.second;
    }
};

class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> mp;
        for(auto i:words)
            mp[i]++;
            
        // min-heap using <string, int> pair
        // priority_queue<pair<string, int>, vector<pair<string, int>>, pairComparator> pq;
        // for(auto i:mp)
        // {
        //     pq.push({i.first, i.second});
        //     if(pq.size() > k)
        //         pq.pop();
        // }
        // vector<string> ret;
        // while(!pq.empty())
        // {
        //     ret.insert(ret.begin(), pq.top().first);
        //     pq.pop();
        // }
        // return ret;
        
        // max-heap using <int, string> pair
        priority_queue<pair<int, string>, vector<pair<int, string>>, pairComparator> pq;
        for(auto i:mp)
            pq.push({i.second, i.first});
            
        vector<string> ret;
        while(k-- && !pq.empty())
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;   
    }
};

int main()
{
    Solution s;
    // vector<string> str = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> str = {"aa", "aaa"};
    vector<string> ret = s.topKFrequent(str, 1);
    for(auto i:ret)
        LOG2(i);
    return 0;
}