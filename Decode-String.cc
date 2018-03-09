#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution 
{
public:

    string recur(int& i, string s)
    {
        if(s.at(i) != '[')
        {
            cout << "invalid recur called\n";
            return "";
        }
        
        i = i+1;
        string temp = "";
        
        while(s.at(i) != ']')
        {
            if(isalpha(s.at(i)))
            {
                temp += s.at(i);
                i++;
            }
                
            else if(isdigit(s.at(i)))
            {
                int j = i;
                string num = "";
                while(isdigit(s.at(j)))
                {    
                    num += s.at(j);
                    j++;
                }
                
                int repeatNum = stoi(num);
                string child = "";
                child = recur(j, s);
                string temp2 = child;
                for(int k = 0; k < repeatNum-1; k++)
                    child += temp2;
                    
                temp += child;
                    
                i = j+1;
            }
        }
        return temp;
        
    }

    string decodeString(string s) 
    {
        string finalStr = "";
        
        for(int i = 0; i < s.size();)
        {
            if(isalpha(s.at(i)))
            {
                finalStr += s.at(i);
                i++;
            }
                
            else if(isdigit(s.at(i)))
            {
                int j = i;
                string num = "";
                while(isdigit(s.at(j)))
                {    
                    num += s.at(j);
                    j++;
                }
                
                int repeatNum = stoi(num);
                //cout << repeatNum << endl;
                string child = "";
                child = recur(j, s);
                string temp = child;
                //cout << temp << endl;
                for(int k = 0; k < repeatNum-1; k++)
                    child += temp;
                //cout << child << endl;
                finalStr += child;
                    
                i = j+1; //the inside, from i to j has been computed by recur of this function
            }
        }
        return finalStr;
    }
};

int main()
{
    Solution s;
    string str = "x11[a2[c]b]e2[t]";
    //string str = "2[t]e3[s]";
    cout << s.decodeString(str) << endl;
    return 0;
}