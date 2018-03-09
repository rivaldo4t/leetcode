#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <math.h>
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

struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
    // needs to be static
    static bool compareInterval(Interval a, Interval b)
    {
        if(a.start < b.start)
            return true;
        if(a.start == b.start && a.end < b.end)
            return true;
        return false;
    }
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) 
    {
        std::vector<Interval> ans;
        if(intervals.size() == 0)
            return ans;
            
        //lambdas
        // std::sort(intervals.begin(), intervals.end(), [](Interval x, Interval y) 
        // {return x.start < y.start;});
        std::sort(intervals.begin(), intervals.end(), compareInterval);
        
        ans.push_back(intervals[0]);
        int index = 0;
        
        std::vector<Interval> :: iterator i;
        
        for(/*auto*/ i = intervals.begin()+1; i != intervals.end(); ++i)
        {
            if(i->start <= ans[index].end)
            {
                ans[index].end = std::max(ans[index].end, i->end);
            }
            else
            {
                ans.push_back(*i);
                index++;
            }
        }
        return ans;
        // return intervals;
    }
};

int main()
{
    Solution s;
    std::vector<Interval> intervals = {{3,4},{2,2},{4,4},{4,5},{0,1},{0,0},{5,6},{0,1},{4,6},{3,4},{3,4}};
    // std::vector<Interval> intervals = {{0,1},{0,0},{0,1}};
    
    std::vector<Interval> ans = s.merge(intervals);
    
    for(auto i:ans)
    {
        LOG1(i.start);
        LOG1(i.end);
        LOG2("");
    }
    
    return 0;
}