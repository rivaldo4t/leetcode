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
    void getPartition(string& s, int index, vector<vector<string>>& ans, vector<string> temp)
    {
        int n = s.size();
        if(index == n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = index; i < s.size(); i++)
        {
            int low = index, high = i;
            while(low < high && s[low] == s[high])
                low++, high--;
            if(low >= high)
            {
                temp.push_back(s.substr(index, i - index + 1));
                getPartition(s, i+1, ans, temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        getPartition(s, 0, ans, temp);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ans = s.partition("aab");
    for(auto i: ans)
        for(auto j:i)
            LOG2(j);
    LOG2("");
    return 0;
}