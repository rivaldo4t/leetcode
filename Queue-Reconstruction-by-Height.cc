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
#include <queue>
#include <list>
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

class Comp
{
public:
    bool operator ()(pair<int, int> a, pair<int, int> b)
    {
        return (a.first > b.first) || ((a.first == b.first) && a.second < b.second);
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) 
    {
        sort(people.begin(), people.end(), Comp());
        // a normal vector would do too
        deque<pair<int, int>> q;
        for(int i = 0; i < people.size(); i++)
            q.insert(q.begin()+people[i].second, people[i]);
        return {q.begin(), q.end()};
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<pair<int, int>> ans = s.reconstructQueue(people);
    for(auto i:ans)
    {
        LOG1(i.first);
        LOG1(i.second);
        LOG2("");
    }
    
    return 0;
}