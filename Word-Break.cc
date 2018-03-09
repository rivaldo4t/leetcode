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
    bool recur(string s, unordered_set<string>& stringSet)
    {
        if(stringSet.count(s) != 0)
            return true;
        
        int low = 0, high = s.size()-1;
        for(int i = low; i <= high; i++)
        {
            string temp = s.substr(0, i-low+1);
            string temp2 = s.substr(i+1, high-i);
            if(stringSet.count(temp) != 0 && recur(temp2, stringSet))
                    return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        
        unordered_set<string> stringSet;
        for(auto i:wordDict)
            stringSet.insert(i);
        
        // TLE
        // return recur(s, stringSet);
        
        vector<bool> dp (s.size()+1 , false);
        dp[0] = true;
        
        for(int len = 1; len <= s.size(); len++)
        {
            // for(int i = 0; i < len; i++)
            for(int i = len - 1; i >= 0; i--)
            {
                string word = s.substr(i, len-i);
                if(dp[i] && stringSet.count(word) != 0)
                {
                    // LOG1(i);
                    // LOG1(len);
                    // LOG2(word);
                    dp[len] = true;
                    break;
                }
            }
        }
        
        // for(auto i:dp)
        //     LOG1(i);
        // LOG2("");
        return dp[s.size()];
    }
};

int main()
{
    Solution s;
    vector<string> wordDict = {"leet", "code", "r"};
    LOG2(s.wordBreak("leetrcode", wordDict));
    return 0;
}