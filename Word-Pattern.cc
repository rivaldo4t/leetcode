#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char, string> map;
        unordered_set<string> set;
        
        int wordStart = 0, letterCount = 0;
        int pattern_iter = 0;
        
        // to catch last word
        str += ' ';
        
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] != ' ')
            {
                letterCount++;
                continue;
            }
            
            string temp = str.substr(wordStart, letterCount);
            wordStart = i+1;
            letterCount = 0;
            
            char c = pattern[pattern_iter];
            
            // LOG2(map[c]);
            // If k does not match the key of any element in the container, 
            // the function inserts a new element with that key and returns a reference to its mapped value.
            
            if(map.count(c))
            {
                if((map[c] != temp))
                    return false;
            }
            else if(!set.insert(temp).second)
                return false;
            
            map[c] = temp;
            pattern_iter++;
        }
        if(pattern_iter != pattern.size())
            return false;
        return true;
    }
};

int main()
{
    Solution s;
    LOG2(s.wordPattern("aba", "dog cat dog"));
    return 0;
}