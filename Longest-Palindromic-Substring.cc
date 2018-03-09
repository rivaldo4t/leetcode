#include <iostream>
using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        int palindrome[n][n];
        int i, j;
        int I = 0;
        int J = 0;
        int max = 0;
        for(i=0; i<n;i++)
        {
            for(j=0; j<n;j++)
            {
                if(i==j)
                    palindrome[i][i] = 1;
                else if (i > j)
                    palindrome[i][j] = -100;
                else if (i + 1 == j)
                    palindrome[i][j] = (s.at(i) == s.at(j));
            }
        }
        
        //filled column wise for DP to hold
        for(j=0; j<n;j++)
        {
            for(i=0; i<n;i++)
            {
                if(i<j-1)
                    palindrome[i][j] = (palindrome[i+1][j-1]) && (s.at(i) == s.at(j));
                
                if (palindrome[i][j] && max < j-i)
                {
                    max = j-i;
                    I=i;
                    J=j;
                }
            }
            
        }
#if 0
        for(i=0; i<n;i++)
        {
            for(j=0; j<n;j++)
            {
                cout << palindrome[i][j] << "\t";
            }
            cout << "\n";
        }
#endif   
        return s.substr(I, J-I+1);
    }
};

int main() 
{
    string s = "cbbd";
    Solution S;
    cout << S.longestPalindrome(s) << endl;
}