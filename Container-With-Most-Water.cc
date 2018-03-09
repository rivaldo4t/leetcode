#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int low = 0, high = height.size()-1;
        int A;
        int maxA = -1;
        int minH;
        while(low < height.size() && high >=0 && low < high)
        {
            minH = min(height[low], height[high]);
            A = minH * (high-low);
            if(A > maxA)
                maxA = A;
            if(minH == height[low])
                low++;
            else if(minH == height[high])
                high--;
        }
        return maxA;
    }
};

int main()
{
    Solution s;
    vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(h) << endl;
    return 0;
}