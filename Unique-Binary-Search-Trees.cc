#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    int numTrees(int n) 
    {
        if(n < 3)
            return n;
            
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            int temp = 0;
            for(int j = 1; j <= i; j++)
            {
                temp += dp[i-j] * dp[j-1];
            }
            dp[i] = temp;
        }
        
        for(auto i:dp)
            cout << i << " ";
        cout << endl;
        
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.numTrees(5) << endl;
    return 0;
}