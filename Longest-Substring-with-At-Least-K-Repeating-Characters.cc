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
    int longestSubstring(string s, int k) 
    {
        if(k > s.size())
            return 0;
        unordered_map<char, int> mp;
        for(auto i:s)
            mp[i]++;
        
        int low = 0, high = s.size()-1;
        while(low < s.size() && mp[s[low]] < k)
            low++;
        while(high >= 0 && mp[s[high]] < k)
            high--;
            
        int index;
        for(index = low; index <= high; index++)
        {
            if(mp[s[index]] < k)
                return max( longestSubstring(s.substr(low, index - low + 1), k),
                            longestSubstring(s.substr(index+1, high - (index+1)+1),k));
        }
        
        return index == high+1 ? high - low + 1 : 0;
    }
};

int main()
{
    Solution s;
    LOG2(s.longestSubstring("a", 1));
    return 0;
}