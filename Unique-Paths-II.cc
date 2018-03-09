#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
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
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) 
    {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp (n, std::vector<int>(m, 0));
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;
        else
            dp[0][0] = 1;
        
        int i = 1;
        while(obstacleGrid[i-1][0] != 1 && i < n)
        {
            dp[i][0] = 1;
            i++;
        }
        int j = 1;
        while(obstacleGrid[0][j-1] != 1 && j < m)
        {
            dp[0][j] = 1;
            j++;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                dp[i][j] =  (obstacleGrid[i][j-1] == 0 ? dp[i][j-1] : 0) +
                            (obstacleGrid[i-1][j] == 0 ? dp[i-1][j] : 0);
            }
        }
        return dp[n-1][m-1];
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> obstacleGrid = {  {0,0,0},
                                                    {0,1,1},
                                                    {0,1,0}, };
    LOG2(s.uniquePathsWithObstacles(obstacleGrid));
    return 0;
}