#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl
using namespace std;

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
    vector<vector<string>> boards;
    
    bool isValid(vector<string>& board, int row, int col)
    {
        int N = board.size();
        int i, j;
        
        for(i = 0; i < col; i++)
            if(board[row][i] == 'Q')
                return false;
        
        for(i = row, j = col; i >= 0 && j >= 0 ; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        
        for(i = row, j = col; j >= 0 && i < N ; i++, j--)
            if(board[i][j] == 'Q')
                return false;
        return true;
    }
    
    bool recur(vector<string>& board, int col)
    {
        int N = board.size();
        if(col >= N)
            return true;
            
        for(int i = 0; i < N; i++)
        {
            if(isValid(board, i, col))
            {
                board[i][col] = 'Q';
                if(recur(board, col+1) == true)
                    boards.push_back(board);
                board[i][col] = '.';
            }
        }
        return false;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        recur(board, 0);
        return boards;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(8);
    for(auto i:ans)
    {
        for(auto j:i)
            LOG2(j);
        LOG2("");
    }
    return 0;
}