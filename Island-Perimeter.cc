#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==0)
                    continue;
                
                if(i == 0 || grid[i-1][j] == 0)
                    perimeter++;
                if(i == grid.size()-1 || grid[i+1][j] == 0)
                    perimeter++;
                if(j == 0 || grid[i][j-1] == 0)
                    perimeter++;
                if(j == grid[i].size()-1 || grid[i][j+1] == 0)
                    perimeter++;
            }
        }
        return perimeter;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a = 
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    cout << s.islandPerimeter(a) << endl;
    return 0;
}