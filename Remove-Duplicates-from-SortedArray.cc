#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:

    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        int index = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[index])
            {
                continue;
            }
            else
            {
                index = index + 1;
                swap(nums[i], nums[index]);
            }
            // for(auto k:nums)
            //     cout << k;
            // cout << endl;
        }
        return index + 1;
    }
};

int main()
{
    Solution s;
    vector<int> n = {1, 1, 1, 2, 2, 2, 3};
    cout << s.removeDuplicates(n) << endl;
    return 0;
}