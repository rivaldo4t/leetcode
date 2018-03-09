#include <iostream>
using namespace std;

bool backtrack(int i, int n, int* a)
{
    cout << "entered\n";
    if(a[i] == 0)
        return false;
    else if(i == n-1)
        return true;
    else
    {
        bool decision = false;
        //for(int j = 1; j <= a[i]; j++)
        for(int j = a[i]; j > 0; j--)
        {
            if(i+j >= n-1)
            {
                decision =  true;
                break;
            }
            else
                decision = decision || backtrack(i+j, n, a);
        }
        return decision;
    }
}

bool canJump(int* nums, int numsSize) 
{
    if(numsSize == 1)
        return true;
    int temp = nums[0];
    for(int i=1;i<numsSize;i++)
        temp = temp && nums[i];
        
    if(temp == 0)
        return backtrack(0, numsSize, nums);
    else
        return true;
}

bool canIt(int* nums, int numsSize)
{
    int memo[numsSize];
    for (int i = 0; i< numsSize; i++)
        memo[i] = -1;
    memo[numsSize-1] = 1;
    
    int jump;
    for (int i = numsSize - 2; i >= 0; i--)
    {
        jump = nums[i];
        int j;
        for(j = 1; j <= jump; j++)
        {
            if(memo[i+j] == 1)
            {
                memo[i] = 1;
                break;
            }
        }
        if (j == jump + 1)
            memo[i] = 0;
    }
    
    return memo[0];
}

int main()
{
    int a[] = {3, 2, 1, 0, 4};
    int size = sizeof(a)/sizeof(a[0]);
    cout << canIt(a, size) << endl;
    return 0;
}