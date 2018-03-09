#include <iostream>
using namespace std;

int search(int* nums, int numsSize, int target) 
{
    int i;
    if(numsSize == 0){}
    
    else if(target >= nums[0])
    {
        i=0;
        while(i < numsSize)
        {
            //cout << i << " " << nums[i] << endl;
            if (target < nums[i])
                break;
            else if (target == nums[i])
                return i;
            else 
                i++;
        }
    }
    
    else if (target <= nums[numsSize-1])
    {
        i = numsSize-1;
        while(i >= 0)
        {
            //cout << i << " " << nums[i] << endl;
            if (target > nums[i])
                break;
            else if (target == nums[i])
                return i;
            else 
                i--;
        }
    }
    
    return -1;
}

int main()
{
    int a[] = {11, 12, 13, 9, 10};
    int size = sizeof(a)/sizeof(a[0]);
    cout << search(a, size, 9) << endl;
    return 0;
}