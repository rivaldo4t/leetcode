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
    string minWindow(string s, string t) 
    {
        vector<int> map(128, 0);
        int minLen = INT_MAX;
        int begin = 0, end = 0, head = 0;
        int counter = t.size();
        
        for(auto i:t)
            map[i]++;
        
        while(end < s.size())
        {
            if(map[s[end++]]-- > 0)
                counter--;
            
            while(counter == 0)
            {
                if(end - begin < minLen)
                {
                    minLen = end - begin;
                    head = begin;
                }
                
                if(map[s[begin++]]++ == 0)
                    counter++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};

int main()
{
    Solution s;
    // LOG2(s.minWindow("ADOBECODEBANC", "ABC"));
    LOG2(s.minWindow("AD", "D"));
    return 0;
}