#include <iostream>
using namespace std;

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int i, j, t;
    int up = 0, left = 0;
    int right = matrixColSize-1, down = matrixRowSize-1;
    int numSize = matrixColSize*matrixRowSize;
    enum traverse {row, col};
    enum direction {incr, decr};
    int *b = (int*)malloc(matrixRowSize*matrixColSize*sizeof(int));
    
    t = 0;
    i = 0; 
    j = 0;
    enum traverse tr = col;
    enum direction dr = incr;
    
    while(t!=numSize)
    {
        if(tr == col && dr == incr)
        {
            if(j > right)
            {
                tr = row;
                dr = incr;
                right--;
                i++;
                j--;
            }
            else
            {
                b[t] = matrix[i][j];
                t++;
                j++;
            }
        }
        
        else if(tr == row && dr == incr)
        {
            if(i > down)
            {
                tr = col;
                dr = decr;
                down--;
                i--;
                j--;
            }
            else
            {
                b[t] = matrix[i][j];
                t++;
                i++;
            }
        }
        
        else if(tr == col && dr == decr)
        {
            if(j < left) 
            {
                tr = row;
                dr = decr;
                left++;
                i--;
                j++;
            }
            else
            {
                b[t] = matrix[i][j];
                t++;
                j--;
            }
        }
        
        else if(tr == row && dr == decr)
        {
            if(i <= up) //not < since we started from up (first row), so dont traverse first row again
            {
                tr = col;
                dr = incr;
                up++;
                i++;
                j++;
            }
            else
            {
                b[t] = matrix[i][j];
                t++;
                i--;
            }
        }
    }
        
    return b;
}

int main()
{
    int i, j, t;
    
    int *a[5];
    for (i = 0; i < 5; i++)
        a[i] = new int[5];
    t = 1;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            a[i][j] = t;
            t++;
        }
    }

    int *b = spiralOrder(a, 5, 5);
    for (i = 0; i < 25; i++)
        cout << b[i] << "->";
    cout << endl;
    
    return 0;
}