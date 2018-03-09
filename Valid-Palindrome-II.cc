#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:

    bool recur(string s, int low, int high)
    {
        while(low < high)
        {
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }

    bool validPalindrome(string s) 
    {
        int low = 0, high = s.length()-1;
        int d = 0;
        while(low < high)
        {
            //won't work because we need to check for both low to high-1 and low+1 to high
            //this only considers one due to else if
            // cout << low << " " << high << endl;
            // if(s[low] == s[high])
            // {
            //     low++;
            //     high--;
            // }
            // else if(s[low] == s[high-1])
            // {
            //     high--;
            //     d++;
            // }
            // else if(s[low+1] == s[high])
            // {
            //     low++;
            //     d++;
            // }
            // else
            //     return false;
            if(s[low] != s[high])
                return recur(s, low, high-1) || recur(s, low+1, high);
            low++;
            high--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.validPalindrome("ebcbbececabbacecbbcbe") << endl;
    return 0;
}