#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int memo[n+1];
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(2) << endl;
    return 0;
}