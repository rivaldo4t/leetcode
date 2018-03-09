#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <bitset>
#define LOG1(x) std::cout << x << " "
#define LOG2(x) std::cout << x << std::endl

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
    std::vector<std::string> findRepeatedDnaSequences(std::string s) 
    {
        // std::unordered_set<std::string> str;
        // std::unordered_set<std::string> strUnique;
        // std::vector<std::string> ans;
        // for(int i = 0; i < s.size(); i++)
        // {
        //     std::string temp = s.substr(i, 10);
        //     if(str.find(temp) == str.end())
        //         str.insert(temp);
        //     else
        //         strUnique.insert(temp);
        // }
        // for(auto i:strUnique)
        //     ans.push_back(i);
        // return ans;
        
        // bit-manipulation1
        // std::unordered_set<int> foundOnce;
        // std::unordered_set<int> foundTwice;
        // std::vector<std::string> res;
        // int* encode = new int[26]();
        // encode['A'-'A'] = 0;
        // encode['C'-'A'] = 1;
        // encode['G'-'A'] = 2;
        // encode['T'-'A'] = 3;
        
        // int hash = 0;
        // for(int i = 0; i < s.size(); i++)
        // {
        //     //create space for new char which takes only 2 bits to represent 
        //     // due to only A,C,G,T
        //     hash = (hash << 2);
        //     hash = hash | encode[s[i]-'A'];
        //     // 0xfffff = 20 bits of 1 so that when hash becomes > 20 bits, 
        //     // '&' removes the 21st and 22nd bit
        //     // done to get hash for new string without looping all 10 chars again;
        //     hash = hash & 0xfffff;
        //     if(i < 9)
        //         continue;

        //     if(!foundOnce.insert(hash).second && foundTwice.insert(hash).second)
        //         res.push_back(s.substr(i-9, 10));
        // }
        // return res;
        
        
        //bit-manipulation2
        // each string is represented as 20 bit number in above solution
        // there are 2^20 possible string
        // use a bitset as a hashset
        std::bitset<1<<20> S1, S2;
        std::vector<std::string> res;
        // int* encode = new int[26]; - garbage initialized
        int* encode = new int[26](); // zero initialized
        encode['A'-'A'] = 0;
        encode['C'-'A'] = 1;
        encode['G'-'A'] = 2;
        encode['T'-'A'] = 3;
        
        int hash = 0;
        for(int i = 0; i < s.size(); i++)
        {
            hash = (hash << 2);
            hash = hash | encode[s[i]-'A'];
            hash = hash & 0xfffff;
            
            if(i < 9)
                continue;

            if(S2[hash])
                continue;
            else if(S1[hash])
            {
                res.push_back(s.substr(i-9, 10));
                S2.set(hash);
            }
            else
                S1.set(hash);
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> ans = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(auto i:ans)
        LOG1(i);
    LOG2("");
    return 0;
}