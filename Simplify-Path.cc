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
        // /..a/ case missing
//     std::deque<std::string> stk;
// public:
//     std::string simplifyPath(std::string path) 
//     {
//         for(int i = 0; i < path.size(); i++)
//         {
//             if(isalpha(path[i]))
//             {
//                 std::string temp(1,path[i++]);
//                 while(isalpha(path[i]))
//                     temp += path[i++];
//                 stk.push_back(temp);
//             }
//             if(path[i] == '.')
//             {
//                 i++;
//                 int count = 1;
//                 while(path[i] == '.')
//                 {
//                     count++;
//                     i++;
//                 }
//                 if(count == 2 && !stk.empty())
//                     stk.pop_back();
//                 else if(count > 2)
//                     stk.push_back(*(new std::string(count, '.')));
//             }
//         }
        
//         std::string shortPath = "";
//         while(!stk.empty())
//         {
//             shortPath += '/' + stk.front();
//             stk.pop_front();    
//         }
//         return shortPath == "" ? "/" : shortPath;
//     }

std::vector<std::string> sp;
public:
    std::string simplifyPath(std::string path) 
    {
        std::string dir = "";
        path += '/';
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/')
            {
                if(dir == "" || dir == ".");
                else if(dir == "..")
                {
                    if(!sp.empty())
                        sp.pop_back();
                }
                else
                    sp.push_back(dir);
                    
                dir.clear();
            }
            else
            {
                dir += path[i];
            }
        }
        
        std::string shortPath = "";
        if(sp.empty())
            return "/";
        for(auto i:sp)
            shortPath += '/' + i;
        
        return shortPath;
    }
};

int main()
{
    Solution s;
    LOG2(s.simplifyPath("/../a/"));
    return 0;
}