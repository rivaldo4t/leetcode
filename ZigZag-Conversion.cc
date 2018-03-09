#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1)
            return s;
        string str = "";
        
        // 450/1150; fails for abcd, 3
        // vector<int> a;
   
        // for(int i = 0; i < s.length(); i += 2*numRows - 2)
        // {
        //     str += s[i];
        //     a.push_back(i);
        // }
        
        // for(int i = 1; i < numRows - 1; i++)
        // {
        //     for(int j = 0; j < a.size(); j++)
        //     {
        //         if(a[j] - i > 0)
        //             str += s[a[j]-i];
        //         if(a[j] + i < s.length())
        //             str += s[a[j]+i];
        //     }
        // }
        
        // for(int i = numRows - 1; i < s.length(); i += 2*numRows - 2)
        //     str += s[i];
            
        // return str;
        
        // Try abcd... with numrows 5 to understand
        // check indices of the chars in same row and how they
        // alternate between two values and find the pattern
        for(int i = 0; i < s.length(); i += 2*numRows-2)
        {
            str += s[i];
        }
        
        int n = 2;
        for(int i = 1; i < numRows - 1; i++)
        {
            int j = i;
            int flag = 0;
            while(j < s.length())
            {
                str += s[j];
                if(!flag)
                {
                    j += 2*numRows - 2*n;
                }
                else
                {
                    j += 2*n - 2;
                }
                flag = !flag;
            }
            n++;
        }
        
        for(int i = numRows-1; i < s.length(); i += 2*numRows-2)
        {
            str += s[i];
        }
        return str;
    }
};

int main()
{
    Solution s;
    string str = "ABCDE";
    int n = 4;
    cout << s.convert(str, n) << endl;
    return 0;
}