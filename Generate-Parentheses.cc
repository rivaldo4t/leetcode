#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl

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
    void recur(std::vector<std::string>& ans, std::string curr, int open, int close, int numPair)
    {
        if(open == numPair && close == numPair)
        {
            ans.push_back(curr);
            return;
        }
        
        if(open < numPair)
            recur(ans, curr + "(", open + 1, close, numPair);
        if(close < open)
            recur(ans, curr + ")", open, close + 1, numPair);
        
        return;
    }
public:
    std::vector<std::string> generateParenthesis(int n) 
    {
        // missing solutions for n = 4 - (())(())
        // std::vector<std::string> ans;
        // if(n < 1)
        //     return ans;
            
        // ans.push_back("()");
        
        // for(int i = 2; i <= n; i++)
        // {
        //     std::set<std::string> temp;
        //     for(auto j:ans)
        //     {
        //         temp.insert("(" + j + ")");
        //         temp.insert("()" + j);
        //         temp.insert(j + "()");
        //     }
            
        //     ans.clear();
        //     for(auto j:temp)
        //         ans.push_back(j);
        // }
        
        // return ans;
        
        std::vector<std::string> ans;
        recur(ans, "", 0, 0, n);
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> ans = s.generateParenthesis(3);
    for(auto i:ans)
        LOG2(i);
    return 0;
}