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
#include <queue>
#include <list>
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
    bool inRange(char c)
    {
        return (c - '0' >= 1 && c - '0' <= 9 || c == '.');
    }
    
    bool isValidSudokuVector(vector<char> vec)
    {
        set<char> check;
        for(auto i:vec)
        {
            if(i == '.')
                continue;
                
            if(!inRange(i))
                return false;
            
            if(check.find(i) != check.end())
                return false;
            else
                check.insert(i);
        }
        return true;
    }
    
    bool isValidSudokuSquare(vector<vector<char>>& board, int i, int j)
    {
        set<char> check;
        for(int x = i; x < i+3; x++)
        {
            for(int y = j; y < j+3; y++)
            {
                // LOG1(board[x][y]);
                if(board[x][y] == '.')
                    continue;
                
                if(!inRange(board[x][y]))
                    return false;
                    
                if(check.find(board[x][y]) != check.end())
                    return false;
                else
                    check.insert(board[x][y]);
            }
            // LOG2("");
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // int row = board.size(), col = board[0].size();
        
        // for(int i = 0; i < row; i++)
        //     if(!isValidSudokuVector(board[i]))
        //         return false;
        
        // for(int j = 0; j < col; j++)
        // {
        //     vector<char> temp;
        //     for(int i = 0; i < row; i++)
        //         temp.push_back(board[i][j]);
        //     if(!isValidSudokuVector(temp))
        //         return false;
        // }
        
        // for(int i=0; i < row; i += 3)
        //     for(int j = 0; j < col; j += 3)
        //         if(!isValidSudokuSquare(board, i, j))
        //             return false;
                
        // return true;
        //
        
        // set<string> check;
        // for(int i = 0; i < 9; i++)
        // {
        //     for(int j = 0; j < 9; j++)
        //     {
        //         if(board[i][j] != '.')
        //         {
        //             if( !check.insert(to_string(board[i][j]) + " in row " + to_string(i)).second ||
        //                 !check.insert(to_string(board[i][j]) + " in col " + to_string(j)).second ||
        //                 !check.insert(to_string(board[i][j]) + " in sq " + to_string(i/3) + "-" + to_string(j/3)).second )
        //             {
        //                 for(auto s:check)
        //                     LOG2(s);
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;
        //
        
        int seenRow[9][9] = {0}, seenCol[9][9] = {0}, seenSq[9][9] = {0};
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3;
                    // is num in row i || is num in col j || is num in sq k
                    if(seenRow[i][num] || seenCol[j][num] || seenSq[k][num])
                        return false;
                    seenRow[i][num] = seenCol[j][num] = seenSq[k][num] = 1;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board =    
                                    // {
                                    //     {'.','8','7','6','5','4','3','2','1'},
                                    //     {'2','.','.','.','.','.','.','.','.'},
                                    //     {'3','.','.','.','.','.','.','.','.'},
                                    //     {'4','.','.','.','.','.','.','.','.'},
                                    //     {'5','.','.','.','.','.','.','.','.'},
                                    //     {'6','.','.','.','.','.','.','.','.'},
                                    //     {'7','.','.','.','.','.','.','.','.'},
                                    //     {'8','.','.','.','.','.','.','.','.'},
                                    //     {'9','.','.','.','.','.','.','.','.'}
                                    // };
                                    
                                    {
                                        {'.','.','5','.','.','.','.','.','6'},
                                        {'.','.','.','.','1','4','.','.','.'},
                                        {'.','.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','9','2','.','.'},
                                        {'5','.','.','.','.','2','.','.','.'},
                                        {'.','.','.','.','.','.','.','3','.'},
                                        {'.','.','.','5','4','.','.','.','.'},
                                        {'3','.','.','.','.','.','4','2','.'},
                                        {'.','.','.','2','7','.','6','.','.'}
                                    };
    LOG2(s.isValidSudoku(board));
    return 0;
}