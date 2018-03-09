#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        vector<int> a(nums.size(), 0);
        
        a[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            a[i] = max(a[i-1] + nums[i], nums[i]);
            
        int maxsum = a[0];
        for(int i = 1; i < a.size(); i++)
        {
            if(a[i] > maxsum)
                maxsum = a[i];
        }
        
        return maxsum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}