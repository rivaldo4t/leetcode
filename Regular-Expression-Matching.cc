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
    bool isMatch(string s, string p) 
    {
        // recursive
        // if(p.empty())
        //     return s.empty();
            
        // bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        // if(p.size() >= 2 && p[1] == '*')
        //     return (firstMatch && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        // else
        //     return firstMatch && isMatch(s.substr(1), p.substr(1));
        
        // iterative
        vector<vector<bool>> dp (s.size()+1, vector<bool> (p.size()+1, false));
        dp[s.size()][p.size()] = true;
        
        for(int i = s.size(); i >= 0; i--)
        {
            for(int j = p.size()-1; j >= 0; j--)
            {
                bool firstMatch = (i < s.size()) && (s[i] == p[j] || p[j] == '.');
                if(j+1 < p.size() && p[j+1] == '*')
                    dp[i][j] = (firstMatch && dp[i+1][j]) || dp[i][j+2];
                else
                    dp[i][j] = firstMatch && dp[i+1][j+1];
            }
        }
        
        return dp[0][0];
    }
};

int main()
{
    Solution s;
    LOG2(s.isMatch("aaa", "aa"));
    return 0;
}