#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    
    int min(int a, int b)
    {
        return a<b?a:b;
    }

    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        int dp[row+1][col+1];
        
        int ans = 0;
        for(int i = 0; i <= row; i++)
        {
            for(int j = 0; j <= col; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(matrix[i-1][j-1] == '1')
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                else
                    dp[i][j] = 0;
                    
                if(dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
        
        for(int i = 0; i <= row; i++)
        {
            for(int j = 0; j <= col; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        return ans*ans;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> a = {
                                {'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}
                            };
    cout << s.maximalSquare(a) << endl;
    return 0;
}