#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool doesIt(int i, int j, int row, int col, vector<vector<char>>& board, string word, vector<vector<int>>& visited)
    {
        if(board[i][j] != word[0])
            return false;
            
        if(word.length() == 1)
            return true;
            
        visited[i][j] = 1;
        
        string sub = word.substr(1, word.length());
        
        if((j < col - 1) && !visited[i][j+1] && doesIt(i, j+1, row, col, board, sub, visited))
            return true;
        if((i < row - 1) && !visited[i+1][j] && doesIt(i+1, j, row, col, board, sub, visited))
            return true;
        if((j > 0) && !visited[i][j-1] && doesIt(i, j-1, row, col, board, sub, visited))
            return true;
        if((i > 0) && !visited[i-1][j] && doesIt(i-1, j, row, col, board, sub, visited))
            return true;
        
        //reset if none of the above to consider in some other path
        visited[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        int row = board.size();
        int col = board[0].size();
        
        if (word.length() > row * col)
            return false;
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(board[i][j] == word[0])
                {
                    vector<vector<int>> visited (row, vector<int> (col, 0));
                    if (doesIt(i, j, row, col, board, word, visited))
                    {
                        for(int i = 0; i < row; i++)
                        {
                            for(int j = 0; j < col; j++)
                            {
                                cout << visited[i][j];
                            }
                            cout << endl;
                        }
                        return true;
                    }
                }
        return false;
    }
};

int main()
{
    vector<vector<char>> board 
    {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };
    string word = "ABCEFSADEESE";
    Solution s;
    cout << s.exist(board, word) << endl;
    
    return 0;
}