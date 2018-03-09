#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution 
{
public:

    void recur(vector<int>& c, vector<vector<int>>& b, vector<int>& temp, int t, int i)
    {
        if(t == 0)
        {
            b.push_back(temp);
            return;
        }
        
        else if(t < 0 || i >= c.size())
            return;
        
        // don't consider this element in sum
        recur(c, b, temp, t, i+1);
        
        // consider this elemet in sum
        temp.push_back(c[i]);
        // note there is "i" in the param, not i+1
        // since repeated elements are allowed
        // for ex. 2367, sum=7 => 223, 7
        // here 2 should be considered again after first selection of it
        recur(c, b, temp, t - c[i], i);
        // restore temp for parent
        temp.pop_back();
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> b;
        vector<int> temp;
        recur(candidates, b, temp, target, 0);
        return b;
    }
};

int main()
{
    Solution s;
    vector<int> a = {4, 6, 3, 7};
    vector<vector<int>> b = s.combinationSum(a, 7);
    for(auto i:b)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}