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
        // TLE 935 / 1805
        // if(s.empty())
        // {
        //     for(int i = 0; i < p.size(); i++)
        //         if(p[i] != '*')
        //             return false;
        //     return true;
        // }
        // if(p.empty())
        //     return s.empty();
        // bool firstMatch = s[0] == p[0] || p[0] == '?' || p[0] == '*';
        // if(p[0] == '*')
        //     return firstMatch && (isMatch(s.substr(1), p) || isMatch(s.substr(1), p.substr(1)) || isMatch(s, p.substr(1)));
        // else
        //     return firstMatch && isMatch(s.substr(1), p.substr(1));
        
        // DP
        // vector<vector<bool>> dp (s.size()+1, vector<bool> (p.size()+1, false));
        // dp[s.size()][p.size()] = 1;
        // for(int i = p.size()-1; i >=0 ; --i)
        // {
        //     if(p[i] == '*')
        //         dp[s.size()][i] = true;
        //     else
        //         break;
        // }
        
        // for(int i = s.size()-1; i >=0 ; --i)
        // {
        //     for(int j = p.size()-1; j >=0 ; --j)
        //     {
        //         if(s[i] == p[j] || p[j] == '?')
        //             dp[i][j] = dp[i+1][j+1];
        //         else if(p[j] == '*')
        //             dp[i][j] = dp[i+1][j] || dp[i][j+1];
        //     }
        // }
        // return dp[0][0];
        
        // iterative
        int i = 0, j = 0, si = -1, sj = -1;
        for(; i < s.size(); i++, j++)
        {
            if(p[j] == '*')
            {
                si = i;
                sj = j;
                i--;
            }
            else if(s[i] != p[j] && p[j] != '?')
            {
                if(si >= 0)
                {
                    i = si;
                    j = sj;
                    si++;
                }
                else
                    return false;
            }
        }
        while(p[j] == '*')
            j++;
        return j == p.size();
    }
};

int main()
{
    Solution s;
    LOG2(s.isMatch("a", "*?*"));
    return 0;
}