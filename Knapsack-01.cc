#include <iostream>
using namespace std;

#define minSum -9999

int max(int a, int b)
{
    return a>b?a:b;
}
/*
//Recursive
int knapsack(int v[], int w[], int i, int W)
{
    int maxSum = 0;
    if(i == 0)
        maxSum = 0;
    else if (W < w[i-1])
        maxSum = knapsack(v, w, i-1, W);
    else
        maxSum = max (knapsack(v, w, i-1, W), v[i-1] + knapsack(v, w, i-1, W - w[i-1]));
    return maxSum;
}
*/

//DP
int knapsack(int v[], int w[], int i, int W)
{
    int table[i+1][W+1];
    
    for(int p = 0; p <= i; p++)
    {
        for(int q = 0; q <= W; q++)
        {
            if(p == 0 || q == 0)
                table[p][q] = 0;
            else if (q < w[p-1])
                table[p][q] = table[p-1][q];
            else
                table[p][q] = max (table[p-1][q], v[p-1] + table[p-1][q - w[p-1]]);
        }
    }
    
    return table[i][W];
}

int main()
{
    int v[] = {60, 100, 120};
    int w[] = {10, 20, 30};
    int W   = 50;
    int size = sizeof(v)/sizeof(v[0]);
    cout << knapsack(v, w, size, W) << "\n";
    return 0;
}