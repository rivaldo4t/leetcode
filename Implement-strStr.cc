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
    int strStr(string haystack, string needle) 
    {
        // return haystack.find(needle);
        if(needle.empty())
            return 0;
        for(int i = 0; i < haystack.size() - needle.size() + 1; i++)
        {
            int j;
            for(j = 0; j < needle.size(); j++)
                if(needle[j] != haystack[i+j])
                    break;
            if(j == needle.size())
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    LOG2(s.strStr("hello", "lo"));
    return 0;
}