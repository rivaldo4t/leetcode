#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++)
        {
            for(int j = i; j < n-i-1 ; j++)
            {
                int temp                = matrix[i][j];
                matrix[i][j]            = matrix[n-1-j][i];
                matrix[n-1-j][i]        = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]    = matrix[j][n-1-i];
                matrix[j][n-1-i]        = temp;
            }
        }
    }
};

int main()
{
    Solution s;
    
    vector<vector<int>> a = {
                                {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}
                            };
    
    /*
    vector<vector<int>> a = {
                                {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9},
                            };
    */
    s.rotate(a);
    for(auto i : a)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}