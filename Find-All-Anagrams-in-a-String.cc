#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>
using namespace std;

#define LOG1(x) std::cout << x
#define LOG2(x) std::cout << x << std::endl

class Solution 
{
    bool isAnagram(string a, string b)
    {
        if(a.size() != b.size())
            return false;
        int count[26] = {};
        for(int i = 0; i < a.size(); i++)
        {
            count[a[i]-'a']++;
            count[b[i]-'a']--;
        }
        for(auto i:count)
            if(i!=0)
                return false;
        
        return true;
    }
public:
    // vector<int> findAnagrams(string s, string p) 
    // {
    //     std::vector<int> temp;
    //     if(s.size() == 0)
    //         return temp;
            
    //     unordered_set<char> charSet;
    //     for(auto i:p)
    //         charSet.insert(i);
            
    //     for(int i = 0; i < s.size(); i++)
    //         if(charSet.find(s[i]) != charSet.end() && isAnagram(s.substr(i, p.size()), p))
    //             temp.push_back(i);
    //     return temp;
    // }
    
    
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> count_p(26, 0), count_s(26, 0), temp;
        
        for(int i = 0; i < p.size(); i++)
        {
            ++count_p[p[i]-'a'];
            ++count_s[s[i]-'a'];
        }
        
        if(count_p == count_s)
            temp.push_back(0);
            
        for(int i = p.size(); i < s.size(); i++)
        {
            ++count_s[s[i]-'a'];
            --count_s[s[i-p.size()] - 'a'];
            
            if(count_p == count_s)
            temp.push_back(i - p.size() + 1);
        }
        return temp;
    }
};

int main()
{
    Solution s;
    vector<int> temp = s.findAnagrams("cbaebabacd", "abc");
    for(auto i:temp)
        LOG2(i);
    return 0;
}