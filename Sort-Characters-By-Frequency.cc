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
    string frequencySort(string s) 
    {
        map<char, int> mp;
        for(auto chr:s)
            mp[chr]++;
        
        vector<vector<char>> bucket(s.size() + 1);
        for(auto i:mp)
            bucket[i.second].push_back(i.first);
            
        string str = "";
            
        for(int i = bucket.size() - 1; i >= 0; i--)
        {
            int n = bucket[i].size();
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < i; k++)
                    str += bucket[i][j];
            }
        }
        
        return str;
    }
};

int main()
{
    Solution s;
    LOG2(s.frequencySort("aaAbcbbcccc"));
    return 0;
}