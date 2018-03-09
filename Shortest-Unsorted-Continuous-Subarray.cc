#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution 
{
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        // O(n^2)
        // int low = 0, high = nums.size()-1;
        // int lessThanLow, greaterThanHigh;
        // while(low < high)
        // {
        //     lessThanLow = 0; 
        //     greaterThanHigh = 0;
            
        //     for(int i = low; i <= high; ++i)
        //     {
        //         if(nums[i] < nums[low])
        //             ++lessThanLow;
        //         else if(nums[i] > nums[high])
        //             ++greaterThanHigh;
        //     }
            
        //     if(!lessThanLow && !greaterThanHigh)
        //         ++low, --high;
        //     else if(lessThanLow && greaterThanHigh)
        //         return high-low+1;
        //     else if(lessThanLow)
        //         --high;
        //     else if(greaterThanHigh)
        //         ++low;
        // }
        // return 0;
        
        // O(n)
        // the smallest i such that nums[i] != max(0,i)
        // and the greatest i such that nums[i] != min(i,n)
        // must be the answer
        int max_t = INT_MIN, min_t = INT_MAX;
        int l=0, h=-1;
        for(int i = 0, j = nums.size()-1; i < nums.size(), j >=0; i++, j--)
        {
            max_t = max(max_t, nums[i]);
            if(max_t != nums[i])
                h = i;
                
            min_t = min(min_t, nums[j]);
            if(min_t != nums[j])
                l = j;
        }
        return h-l+1;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {2, 4, 3, 1, 1, 5, 6};
    vector<int> nums = {2,6,4,8,10,9,15};
    cout << s.findUnsortedSubarray(nums) << endl;
    return 0;
}