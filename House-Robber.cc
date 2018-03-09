#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:

    int max (int a, int b)
    {
        return a > b ? a : b;
    }

    int rob(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        /*
        vector<int> temp = nums;
        
        temp[1] = max(temp[0], temp[1]);
        for(int i = 2; i < temp.size(); i++)
            temp[i] = max(temp[i]+temp[i-2], temp[i-1]);
            
        return temp[temp.size()-1];
        */
        
        int lastLastMax = nums[0];
        int lastMax = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {
            int c = max (nums[i]+lastLastMax, lastMax);
            lastLastMax = lastMax;
            lastMax = c;
        }
        return max(lastMax, lastLastMax);
        
        /*
        int rob = 0, notrob = 0;
        for(int i=0;i<nums.size();i++)
        {
            int currrob = nums[i] + notrob;
            notrob = max(notrob,rob);
            rob = currrob;
        }
        return max(rob,notrob);
        */
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 50, 10, 35, 25, 60, 15};
    cout << s.rob(nums) << endl;
    return 0;
}