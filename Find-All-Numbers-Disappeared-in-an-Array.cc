#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:

    void swap(int& a, int& b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> ans;
        
        int i = 0;
        while(i < nums.size())
        {
            if(nums[nums[i]-1] != nums[i])
                swap(nums[nums[i]-1], nums[i]);
            else
                i++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i+1)
                ans.push_back(i+1);
                //442. Find All Duplicates in an Array
                //ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = s.findDisappearedNumbers(nums);
    for(auto i:ans)
        cout << i << " ";
    cout << endl;
    return 0;
}