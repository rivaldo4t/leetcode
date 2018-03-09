#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
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
public:
    int reverse(int x) 
    {
        int ans = 0;
        // int sign = 1;
        // if(x < 0)
        //     sign = -1, x = -x;
        int temp;
        while(x)
        {
            temp = ans*10 + x%10;
            if(temp/10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        // return ans * sign;
        return ans;
    }
};

int main()
{
    Solution s;
    LOG2(s.reverse(1534236469));
    // int a = INT_MAX;
    // LOG2(a*56);
    return 0;
}