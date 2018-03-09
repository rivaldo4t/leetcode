#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    string countAndSay(int n) 
    {
        string str = "1";
        if(n == 1)
            return str;
        stack<char> stk;
        int index = 0;
        for(int i = 2; i <= n; i++)
        {
            string newstr = "";
            while(str.size())
            {
                if(stk.empty() || stk.top() == str[0])
                {
                    stk.push(str[0]);
                    str = str.substr(1);
                }
                else
                {
                    int count = 0;
                    char temp;
                    if(!stk.empty())
                        temp = stk.top();
                    while(!stk.empty())
                    {
                        count++;
                        stk.pop();
                    }
                    newstr += count + '0';
                    newstr += temp;
                }
            }
            
            int count = 0;
            char temp;
            if(!stk.empty())
            {
                temp = stk.top();
                while(!stk.empty())
                {
                    count++;
                    stk.pop();
                }
                newstr += count + '0';
                newstr += temp;
            }
            
            str = newstr;
        }
        return str;
    }
};

int main()
{
    Solution s;
    int n = 7;
    cout << s.countAndSay(n) << endl;
    return 0;
}