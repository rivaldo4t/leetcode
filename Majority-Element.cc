#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int num = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == num)
                count++;
            else
            {
                count--;
                if(count == 0)
                {
                    num = nums[i];
                    count = 1;
                }
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    vector<int> a = {3, 2, 3};
    cout << s.majorityElement(a) << endl;;
    return 0;
}