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
    int longestPalindromeSubseq(string s) 
    {
        const int n = s.size();
        
        int dp[n][n];
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        // won't work because the dp values required are not updated yet
        // when they are used
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = i+1; j < n; j++)
        //     {
        //         if(s[i] != s[j])
        //             dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        //         else if (j == i+1)
        //             dp[i][j] = 2;
        //         else
        //             dp[i][j] = dp[i+1][j-1] + 2;
        //     }
        // }
        
        // k is the length of the sub; start from string of length 2
        for(int k = 2; k <= n; k++)
        {
            for(int i = 0; i < n-k+1; i++)
            {
                int j = i+k-1;
                if(s[i] == s[j] && k == 2)
                    dp[i][j] = 2;
                else if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    Solution s;
    LOG2(s.longestPalindromeSubseq("BBABCBCAB"));
    return 0;
}