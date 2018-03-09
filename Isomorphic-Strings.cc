#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char> m;
        unordered_set<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            auto it = m.find(s[i]);
            auto it2 = st.find(t[i]);
        
            if(it == m.end())
            {
                if(it2 != st.end())
                    return 0;
                m.insert(make_pair(s[i], t[i]));
                st.insert(t[i]);
            }
            else if(t[i] != it->second)
                return 0;
        }
        return 1;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("eg", "ee") << endl;
    return 0;
}