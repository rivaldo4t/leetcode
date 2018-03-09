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
    void moveZeroes(vector<int>& nums) 
    {
        int nonZ=-1, Z=0;
        for(Z = 0; Z < nums.size(); Z++)
        {
            if(nums[Z] != 0)
            {
                swap(nums[nonZ+1], nums[Z]);
                nonZ++;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> a = {0, 1, 0, 3, 4};
    s.moveZeroes(a);
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}