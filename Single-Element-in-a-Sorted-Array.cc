#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:

    int recur(vector<int>& nums, int start, int end)
    {
        if(start == end)
            return nums[start];
        int mid = (end + start)/2;
        if(mid%2 == 0)
        {
            if(nums[mid] == nums[mid-1])
                return recur(nums, start, mid-2);    
            else if(nums[mid] == nums[mid+1])
                return recur(nums, mid+2, end);
            else
                return nums[mid];
        }
        else
        {
            if(nums[mid] == nums[mid-1])
                return recur(nums, mid+1, end);
            else if(nums[mid] == nums[mid+1])
                return recur(nums, start, mid-1);
            else
                return nums[mid];
        }
    }

    int singleNonDuplicate(vector<int>& nums) 
    {
        return recur(nums, 0, nums.size()-1);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}