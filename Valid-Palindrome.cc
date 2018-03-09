#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        if(s.length() == 0)
            return true;
        int low = 0, high = s.length()-1;
        while(low < high)
        {
            cout << low << " " << high << endl;
            while(!isalnum(s[low]) && low < high)
                low++;
            while(!isalnum(s[high]) && low < high)
                high--;
            if(tolower(s[low++]) != tolower(s[high--]))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}