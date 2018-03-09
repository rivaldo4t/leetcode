#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2) 
    {
        string temp(num1.size() + num2.size(), '0');
        
        for(int i = num1.size()-1; i >= 0; i--)
        {
            int carry = 0;
            for(int j = num2.size()-1; j >= 0; j--)
            {
                int t = (temp[i+j+1] - '0') + carry + (num1[i] - '0')*(num2[j] - '0');
                temp[i+j+1] = t%10 + '0';
                carry = t/10;
            }
            temp[i] += carry;
        }
        
        size_t startpos = temp.find_first_not_of("0");
        if (string::npos != startpos) 
        {
            return temp.substr(startpos);
        }
        return "0";
    }
};

int main()
{
    Solution s;
    string a = "999";
    string b = "99";
    cout << s.multiply(a, b) << endl;
    return 0;
}