#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:

    void recur(vector<vector<char>>& board, int i, int j)
    {
        
        // for(auto i:board)
        // {
        //     for(auto j:i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        // cout << endl;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || 
            board[i][j] == 'B' || board[i][j] == 'M')
            return;
            
        else if(board[i][j] == 'E')
        {
            board[i][j] = 'B';
            cout << "1\n";
            int count = 0;
            if(j < board[0].size() && board[i][j+1] == 'M')
                count++;
                cout << "2\n";
            if(j > 0 && board[i][j-1] == 'M')
                count++;
                cout << "3\n";
            if(i < board.size()-1 && board[i+1][j] == 'M')
                count++;
                cout << "4\n";
            if(i < board.size()-1 && j < board[0].size()-1 && board[i+1][j+1] == 'M')
                count++;
                cout << "5\n";
            if(i < board.size()-1 && j > 0 && board[i+1][j-1] == 'M')
                count++;
                cout << "6\n";
            if(i > 0 && board[i-1][j] == 'M')
                count++;
                cout << "7\n";
            if(i > 0 && j < board[0].size()-1 && board[i-1][j+1] == 'M')
                count++;
                cout << "8\n";
            if(i > 0 && j > 0 && board[i-1][j-1] == 'M')
                count++;
                cout << "9\n";
                
            if(count != 0)
                board[i][j] = count + '0';
            else
            {
                recur(board, i, j+1);
                recur(board, i, j-1);
                recur(board, i+1, j);
                recur(board, i-1, j);
                recur(board, i+1, j+1);
                recur(board, i+1, j-1);
                recur(board, i-1, j+1);
                recur(board, i-1, j-1);
            }
        }
        return;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        recur(board, click[0], click[1]);
        return board;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = 
    {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click = {3, 0};
    vector<vector<char>> boardAfterClick = s.updateBoard(board, click);
    
    return 0;
}