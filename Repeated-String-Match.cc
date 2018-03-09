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
    int repeatedStringMatch(string A, string B) 
    {
        // naive
        // string a = A;
        // int res;
        // for(res = 1; res <= B.size()/A.size() + 2; res++, a+=A)
        //     if(a.find(B) != string::npos)
        //         return res;
        // return -1;
        
        // 3ms submission from someone
        string temp = A + A;
        size_t pos = temp.find(B.substr(0, A.size()));
        if(pos == string::npos)
            return -1;
            
        int count = 1;
        size_t i = 0;
        while(i < B.size())
        {
            if(pos == A.size())
            {
                pos = 0;
                count++;
            }
            if(A[pos++] != B[i++])
                return -1;
        }
        
        return count;
    }
};

int main()
{
    Solution s;
    LOG2(s.repeatedStringMatch("abcd", "cdabcdab"));
    return 0;
}