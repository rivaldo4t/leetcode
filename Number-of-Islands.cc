#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:

    int ans = 2;
    
    void recur(vector<vector<char>>& grid, int i, int j)
    {
        if(grid[i][j] != '1')
            return;
        
        grid[i][j] = ans + '0';
        
        if(j < grid[0].size()-1)
            recur(grid, i, j+1);
        if(i < grid.size()-1)
            recur(grid, i+1, j);
        if(j > 0)
            recur(grid, i, j-1);
        if(i > 0)
            recur(grid, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size() == 0)
            return 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    recur(grid, i, j);
                    ans++;
                }
            }
        }
        
        return ans-2;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> a = {
                                {'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}
    };
    cout << s.numIslands(a) << endl;
    
    for(auto i:a)
    {
        for(auto j : i)
            cout << j;
        cout << endl;
    }
    
    return 0;
}