#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        if(m==0 || n==0)
            return 0;

        int a[m][n];
        int i, j;
        
        for(i=0; i<m; i++)
            a[i][0] = 1;
        for(i=0; i<n; i++)
            a[0][i] = 1;
            
        for(i=1; i<m; i++)
            for(j=1; j<n; j++)
                a[i][j] = a[i][j-1] + a[i-1][j];
        
        return a[m-1][n-1];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(6,4) << endl;
    return 0;
}