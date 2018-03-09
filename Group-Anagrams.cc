#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> strmap;
        for(int i = 0; i < strs.size(); i++)
        {
            string tmpstr = strs[i];
            sort(tmpstr.begin(), tmpstr.end());
            if(strmap.find(tmpstr) == strmap.end())
                strmap.insert(pair<string, vector<string>> (tmpstr, vector<string>()));
                
            strmap[tmpstr].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for(auto i:strmap)
        {
            result.push_back(i.second);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto t = s.groupAnagrams(strs);
    for(auto i:t)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}