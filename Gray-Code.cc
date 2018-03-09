#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
        vector<int> a = {0};
        for(int i = 0; i < n; i++)
        {
            int size = a.size();
            for(int k = size-1; k >= 0; k--)
            {
                a.push_back(a[k] | 1 << i);
            }
        }
        return a;
    }
};

int main()
{
    Solution s;
    vector<int> a = s.grayCode(5);
    for(auto i:a)
        cout << i << " ";
    cout << endl;
    return 0;
}