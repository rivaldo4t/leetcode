#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        int na = a.size();
        int nb = b.size();
    
        string big, small;
        if(na >= nb)
            big = a, small = b;
        else
            big = b, small = a;
            
        reverse(big.begin(), big.end());
        reverse(small.begin(), small.end());
        int carry = 0;
        string s = "";
        int n;
        int i;
        
        for(i = 0; i < small.size(); i++)
        {
            n = carry + small[i]-'0' + big[i]-'0';
            carry = n/2;
            n %= 2;
            s += n + '0';
        }
        
        if(na == nb)
        {
            if(carry)
                s += "1";
        }
        else
        {
            for(; i < big.size(); i++)
            {
                n = carry + big[i]-'0';
                carry = n/2;
                n %= 2;
                s += n + '0';
            }
            
            if(carry)
                s += "1";
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("11111", "1101") << endl;
    return 0;
}