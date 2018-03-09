#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        if(s.size() == 0)
            return 0;
        
        int i = s.size()-1;
        int lastletter = i;
        while(s[i--] == ' ')
            lastletter = i;
            
        int lastSpace = -1;
        
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ' && i+1<s.size() && s[i+1] != ' ')
                lastSpace = i;
        }
        
        return lastletter - lastSpace;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("itasc   ") << endl;
    return 0;
}