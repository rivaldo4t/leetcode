#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
//         int sum = 0, count = 0;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             sum = 0;
//             for(int j = i; j < nums.size(); j++)
//             {
//                 sum += nums[j];
                
//                 if(sum == k)
//                     count++;
//             }
//         }
        
        unordered_map<int, int> hash;
        // hash.insert(make_pair(0, 1));
        hash[0] = 1;
        int sum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            //if(hash.find(sum-k) != hash.end())
                count += hash[sum-k];
                
            //if(hash.find(sum) != hash.end())
                hash[sum] += 1;
            // else
            //     hash.insert(make_pair(sum, 1));
            
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    cout << s.subarraySum(nums, 7) << endl;
    return 0;
}