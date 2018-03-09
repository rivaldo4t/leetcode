#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        // O(N^2)
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     int num = INT_MIN;
        //     for(int j = 0; j < i; j++)
        //     {
        //         if(nums[j] < nums[i])
        //         {
        //             if(num != INT_MIN && nums[j] > num)
        //                 return true;
        //             else num = nums[j];
        //         }
        //     }
        // }
        // return false;
        
        //O(N) but too many conditions, also 59/61
        // if(nums.size() < 3)
        //     return false;
        // int minIndex = 0, maxIndex = 0;
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[i] >= nums[maxIndex])
        //         maxIndex = i;
                
        //     if(nums[i] < nums[minIndex])
        //         minIndex = i;
        // }
        
        // int temp = -1;
        // if(maxIndex < minIndex)
        // {
        //     if(minIndex != nums.size() - 1)
        //         temp = minIndex + 1;
        //     for(int i = minIndex + 2; i < nums.size(); i++)
        //     {
        //         if(nums[i] >= nums[temp])
        //             temp = i;
        //     }
        // }
        // if(temp != -1)
        //     maxIndex = temp;
            
        // cout << minIndex << endl << maxIndex << endl;
        
        // for(int i = minIndex + 1; i < maxIndex; i++)
        // {
        //     if(nums[i] != nums[minIndex] && nums[i] != nums[maxIndex])
        //         return true;
        // }
        // return false;
        
        int num1 = INT_MAX, num2 = INT_MAX;
        for(auto i:nums)
        {
            if(i < num1)
                num1 = i;
            else if(i < num2)
                num2 = i;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {2, 5, 3, 4, 5};
    vector<int> nums = {1, 2, -10, -8, -7};
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}