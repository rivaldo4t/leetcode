#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        /*
        //time N*log(N), space constant;
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
        */
        
        /*
        //time N*log(k), space N;
        priority_queue <int> pq;
        for(auto& i : nums)
            pq.push(i);
            
        while (pq.size() != nums.size()-k+1)
            pq.pop();
        */
        
        //time N*log(k), space k;
        priority_queue <int, vector<int>, std::greater<int>> pq;
        for(auto& i : nums)
        {
            pq.push(i);
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};

int main()
{
    Solution s;
    vector<int> a = {3,2,1,5,6,4};
    int k = 2;
    cout << s.findKthLargest(a, k) << endl;
    return 0;
}