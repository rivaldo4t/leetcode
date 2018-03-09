#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    
    void recur(vector<int>& nums, vector<vector<int>>& b, int index, vector<int>& temp)
    {
        if(index == nums.size())
        {
            b.push_back(temp);
            return;
        }
            
        // don't push current element, generate further subsets
        recur(nums, b, index + 1, temp);
        
        // push current element and generate further subsets
        temp.push_back(nums[index]);
        recur(nums, b, index + 1, temp);
        temp.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> b;
        vector<int> temp;
        recur(nums, b, 0, temp);
        return b;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2, 3};
    vector<vector<int>> b = s.subsets(a);
    for(auto i:b)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}