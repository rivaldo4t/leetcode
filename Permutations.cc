#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    void recur1(vector<vector<int>>& ret, vector<int>& nums, int i)
    {
        if(i == nums.size() - 1)
        {
            ret.push_back(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++)
        {
            swap(nums[j], nums[i]);
            recur1(ret, nums, i+1);
            swap(nums[j], nums[i]);
        }
    }

    void recur(vector<vector<int>>& ret, vector<int> nums, vector<int>& temp, vector<bool>& used)
    {
        if(temp.size() == nums.size())
        {
            ret.push_back(temp);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i])
                continue;
            temp.push_back(nums[i]);
            used[i] = true;
            recur(ret, nums, temp, used);
            used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        // recur1(ret, nums, 0);
        
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        recur(ret, nums, temp, used);
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2, 3};
    vector<vector<int>> b = s.permute(a);
    for(auto i:b)
    {
        for(auto j:i)
            cout << j;
        cout << endl;
    }
    return 0;
}