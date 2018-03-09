#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            char temp;
            switch(s[i])
            {
                case '(' :
                case '{' :
                case '[' : st.push(s[i]); break;
                case ']' : if(st.empty() || st.top() != '[')
                                return 0;
                            st.pop();
                            break;
                case '}' : if(st.empty() || st.top() != '{')
                                return 0;
                            st.pop();
                            break;
                case ')' : if(st.empty() || st.top() != '(')
                                return 0;
                            st.pop();
                            break;
            }
        }
        return (st.empty());
    }
};

int main()
{
    Solution s;
    string str = "]";
    cout << s.isValid(str) << endl;
    return 0;
}