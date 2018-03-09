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
public:
    bool operator () (pair<char, int> a, pair<char, int> b)
    {
        return (a.second < b.second) || (a.second == b.second && a.first > b.first);
    }
};

class Solution 
{
public:
    string reorganizeString(string S) 
    {
        unordered_map<char, int> mp;
        for(auto i:S)
            mp[i]++;
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, pairComparator> q;    
        for(auto i:mp)
            q.push({i.first, i.second});
            
        if(q.top().second > ceil(S.size()/2.0))
            return "";
            
        string str = "";
        while(!q.empty())
        {
            auto temp = q.top();
            q.pop();
            
            if(str.empty() || str.back() != temp.first)
            {
                str += temp.first;
                temp.second--;
            }
            else if(q.empty())
                return "";
            else
            {
                auto temp = q.top();
                q.pop();
                str += temp.first;
                temp.second--;
                if(temp.second > 0)
                    q.push(temp);
            }
                
            if(temp.second > 0)
                q.push(temp);
        }
        
        return str;
    }
};

int main()
{
    Solution s;
    string str = "aaaabbc";
    LOG2(s.reorganizeString(str));
    return 0;
}