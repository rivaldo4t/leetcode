#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution 
{
public:
    vector<int> countBits(int num) 
    {
        vector<int> temp (num+1, 1);
        temp[0] = 0;
        //temp[1] = 1; //intialized
        
        int powOfTwo = 1;
        for(int i = 2; i <= num; i++)
        {
            if(!(i&(i-1)))
            {
                //temp[i] = 1; //intialized
                powOfTwo = i;
            }
            else
            {
                temp[i] = 1 + temp[i-powOfTwo];
                //Leftmost bit will be a new inclusion after a 
                //new powOfTwo is reached
                //the next three bits are already computed for
                //peer solution leetcode f[i] = f[i >> 1] + (i & 1)
            }
        }
        return temp;
    }
};

int main()
{
    Solution s;
    vector<int> a = s.countBits(10);
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}