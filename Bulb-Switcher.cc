#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution 
{
public:
    int bulbSwitch(int n) 
    {
        if (n==0)
            return 0;
        
        int count = 0;
        /*
        // TLE and MLE
        vector<int> a (n,0);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j+=i+1)
            {
                a[j] ^= 1;
            }
        }

        for(int i = 0; i < n; i++)
            if(a[i] == 1)
                count ++;
        */
        
        /*
        //TLE for last case 100000000
        for(unsigned long long int i = 1; i <= n; i++)
        {
            long long int root(round(sqrt(i)));
            if(root * root == i)
                cout << i << " ", count++;
        }
        return count;
        */
        return sqrt(n);
    }
};

int main()
{
    Solution s;
    int n = 14;
    cout << s.bulbSwitch(n) << endl;
    return 0;
}