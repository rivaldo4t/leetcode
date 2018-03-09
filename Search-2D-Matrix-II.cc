#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        int row = matrix.size();
        if(row == 0)
            return false;
        int col = matrix[0].size();
        if(col == 0)
            return false;
            
        int i=0, j=col-1;
        while(i<row && j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        
        return false;
    }
};

int main()
{
    Solution s;
    /*vector<vector<int>> a = {
                                {1,   4,  7, 11, 15},
                                {2,   5,  8, 12, 19},
                                {3,   6,  9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}
                            };*/
    vector<vector<int>> a = {
                                {2,5},
                                {2,8},
                                {7,9},
                                {7,11},
                                {9,11}
        
    };
    cout << s.searchMatrix(a, 7) << endl;
    return 0;
}