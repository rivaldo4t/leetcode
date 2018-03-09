#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    int hammingDistance(int x, int y)   
    {
        int z = x^y;
        int count = 0;
        while(z)
        {
            if(z&1)
                count++;
            z = z>>1;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
    return 0;
}