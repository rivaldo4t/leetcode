#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:

    int lengthOfLongestSubstring1(string s) 
    {
        int n = s.length();
        int ans = 0;
        int i = 0;
        int j = 0;
        unordered_set<char> set;
        
        while(i < n && j <n)
        {
            if(set.find(s.at(j)) == set.end())
            {
                set.insert(s.at(j));
                j++;
                ans = max(ans, j-i);
            }
            else
            {
                set.erase(set.find(s.at(i)));
                i++;
            }
        }
    
        return ans;
    }

    int lengthOfLongestSubstring2(string s) 
    {
        int n = s.length();
        int max = 1;
        int curr = 1;
        int i = 0;
        int j = 0;
        
        int visited[256];
        for(i=0;i<256;i++)
            visited[i] = -1;
        
        if(s.size()==0)
            return 0;
        visited[s.at(0)] = 0;
        
        for(i=1;i<n;i++)
        {
            j = visited[s.at(i)];
            if (j == -1 || i-curr > j)
                curr++;
            else
            {
                if (curr > max)
                    max = curr;
                curr = i-j;
            }
            visited[s.at(i)] = i;
        }
    
        if (curr > max)
            max = curr;
        
        return max;
    }

    int lengthOfLongestSubstring(string s) 
    {
        vector<int> map (128, 0);
        int maxLen = 0;
        int begin = 0, end = 0;
        int counter = 0;
        
        while(end < s.size())
        {
            if(map[s[end++]]++ > 0)
                counter++;
            while(counter > 0)
                if(map[s[begin++]]-- > 1)
                    counter--;
                    
            maxLen = max(maxLen, end - begin);
        }
        cout << s.substr(begin, maxLen) << endl;
        return maxLen;
    }
};

int main() 
{
    string s = "pwwkew";
    Solution S;
    cout << S.lengthOfLongestSubstring(s) << endl;
}
