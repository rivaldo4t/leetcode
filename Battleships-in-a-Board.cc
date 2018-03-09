#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    void recur(vector<vector<char>>& board, int i, int j)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '.')
            return;
        
        char temp = board[i][j];
        board[i][j] = '.';
        recur(board, i+1, j);
        recur(board, i, j+1);
        recur(board, i-1, j);
        recur(board, i, j-1);
        // if reset the node will be considered again
        // board[i][j] = temp;
    }

    int countBattleships(vector<vector<char>>& board) 
    {
        // Changing the board
        // int count = 0;
        // for(int i = 0; i < board.size(); ++i)
        // {
        //     for(int j = 0; j < board[i].size(); ++j)
        //     {
        //         if(board[i][j] == 'X')
        //         {
        //             count++;
        //             recur(board, i, j);
        //         }
        //     }
        // }
        // return count;
        
        // better approach: count only the heads(topmost-leftmost) nodes
        int count = 0;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] == '.')
                    continue;
                if(i > 0 && board[i-1][j] == 'X')
                // if not topmost
                    continue;
                if(j > 0 && board[i][j-1] == 'X')
                // if not leftmost
                    continue;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {  {'X', '.', 'X'},
                                    {'.', '.', 'X'},
                                    {'.', '.', 'X'}
    };
    cout << s.countBattleships(board) << endl;
    return 0;
}