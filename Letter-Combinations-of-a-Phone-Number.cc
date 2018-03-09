#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    
    unordered_map<char, string> digitMap = 
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'8', "stu"},
        {'9', "wxyz"}
    };

    void recur(vector<string>& out, string digits, string& temp, int index)
    {
        if(index >= digits.size())
        {
            out.push_back(temp);
            return;
        }
        
        string currStr = digitMap.find(digits.at(index))->second;
        for(int i = 0; i < currStr.size(); i++)
        {
            temp.push_back(currStr.at(i));
            recur(out, digits, temp, index + 1);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) 
    {
        vector<string> out;
        if(digits.size() == 0)
            return out;
        string temp = "";
        recur(out, digits, temp, 0);
        return out;
    }
};

int main()
{
    Solution s;
    string a = "23";
    vector<string> str = s.letterCombinations(a);
    for(auto i:str)
        cout << i << endl;
    return 0;
}