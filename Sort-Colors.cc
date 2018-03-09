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
    void sortColors(vector<int>& nums) 
    {
        int  start = 0;
        int end = nums.size()-1;
        for(int i=0; i< nums.size(); i++)
        {
            while(nums[i] == 2 && i < end) 
                swap(nums[i], nums[end--]);
            while(nums[i] == 0 && i > start) 
                swap(nums[i], nums[start++]);
        }
    }
};

int main()
{
    Solution s;
    vector<int> a = {0, 2};
    s.sortColors(a);
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}