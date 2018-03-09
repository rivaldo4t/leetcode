#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution 
{
public:

    int min(int a, int b)
    {
        return a<b?a:b;
    }

    int numSquares(int n) 
    {
        vector<int> dp (n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        
        int temp = round(sqrt(n));
        if(temp * temp == n)
            return 1;
        
        for(int i = 3; i <= n; i++)
        {
            int temp = round(sqrt(i));
            if(temp * temp == i)
            {
                dp[i] = 1;
            }
            else
            {
                int minNum = 99999;
                for(int j = 1; j*j < i; j++)
                {
                    minNum = min(dp[i - j*j] + 1/*=dp[j*j]*/, minNum);
                }
                dp[i] = minNum;
            }
        }
#if 0
        for(auto i:dp)
            cout << i << " ";
        cout << endl;
#endif
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.numSquares(25) << endl;
    return 0;
}