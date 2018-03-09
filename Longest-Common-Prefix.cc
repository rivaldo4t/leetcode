#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string s = "";
        int j=0;
        if (strs.size() == 0)
            return s;
        if (strs.size() == 1)
            return strs[0];
        while(j<strs[0].length() && j<strs[1].length())
        {
            if(strs[0].at(j) == strs[1].at(j))
            {
                s.append(strs[0], j, 1);
                j++;
            }
            else
            {
                break;    
            }
        }
        if(s.length() == 0 || strs.size() == 2)
         return s;
        
        for(vector<string>::const_iterator i = strs.begin()+2; i!=strs.end();++i)
        {
            if((*i).length()==0)
            {
                s = "";
                return s;
            }
            j=0;
            while(j<s.length() && j<(*i).length())
            {
                if((*i).at(j) == s.at(j))
                {
                    j++;
                }
                else
                {
                    //s=s.substr(0, j);
                    //if placed here, will fail when s.length > (*i).length
                    break;
                }
            }
            s=s.substr(0, j);
        }
        return s;
    }
};

int main() 
{
    vector<string> strs = {"aar", "aarc", "aardr", "aarete", "aa"};
    Solution S;
    cout << S.longestCommonPrefix(strs) << endl;
}
