#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        /*
        O(n) space
        int before[nums.size()];
        int after[nums.size()];
        vector<int> productExcept;
        before[0] = 1;
        after[nums.size()-1] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            before[i] = before[i-1] * nums[i-1];
            after[nums.size()-i-1] = after[nums.size()-i] * nums[nums.size()-i];
        }
        for(int i = 0; i < nums.size(); i++)
            productExcept.push_back(before[i] * after[i]);
        */
        
        //O(1) space
        int before = 1;
        int after = 1;
        vector<int> productExcept (nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)
        {
            //start filling like normal before and after arrays and then overwritingly
            //multiply to get the final result
            productExcept[i] *= before;
            before *= nums[i];
            productExcept[nums.size()-i-1] *= after;
            after *= nums[nums.size()-i-1];
        }
        
        return productExcept;
    }
};

int main()
{
    Solution s;
    vector<int> a = {2, 3, 4, 5};
    vector<int> b = s.productExceptSelf(a);
    for(auto i:b)
        cout << i << " ";
    cout << endl;
    return 0;
}