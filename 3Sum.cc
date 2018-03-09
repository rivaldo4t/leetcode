#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) 
            {
                int newsum = -nums[i];
                // vector<int> temp;
                // temp.push_back(nums[i]);
                int low = i+1, high = nums.size()-1;
                while(low < high)
                {
                    if(nums[low] + nums[high] == newsum)
                    {
                        // temp.push_back(nums[low]);
                        // temp.push_back(nums[high]);
                        // //result.push_back(temp);
                        result.push_back(vector<int> {nums[i], nums[low], nums[high]});
                        // temp.pop_back();
                        // temp.pop_back();
                        while(low < high && nums[low] == nums[low+1])
                            low++;
                        while(low < high && nums[high] == nums[high-1])
                            high--;
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] > newsum)
                        high--;
                    else
                        low++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {0, 0, 0, 0, 0, 0};
    auto t = s.threeSum(nums);
    for(auto i:t)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}