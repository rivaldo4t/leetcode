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
    int countSubstrings(string s) 
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int count = 0;
        
        // palindromes of length 1
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            count++;
        }
        
        // palindromes of length 2
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                count++;
            }
        }
                
        // palindromes of length > 2
        for(int k = 3; k <= n; k++)
        {
            for(int i = 0; i < n-k+1; i++)
            {
                int j = i+k-1;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    LOG2(s.countSubstrings("aaa"));
    return 0;
}