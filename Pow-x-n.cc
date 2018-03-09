#include <iostream>
using namespace std;

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        double ans, temp;
        
        if(n==0)
            return double(1);
        else if(n==1)
            return x;
        else if(n==-1)
            return 1/x;
        
        temp = myPow(x, n/2);
        if(n%2==0)
            ans = temp * temp;
        else
        {
            if(n<0)
                ans = temp * temp * 1/x;
            else
                ans = temp * temp * x;
        }
            
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, -3) << endl;
}