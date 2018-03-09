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

class Solution 
{
    vector<list<int>> makeGraph(int numCourses, vector<int>& inDeg, vector<pair<int, int>>& prerequisites)
    {
        vector<list<int>> adjList(numCourses, list<int>());
        for(auto i:prerequisites)
        {
            adjList[i.second].push_back(i.first);
            inDeg[i.first]++;
        }
        return adjList;
    }
    bool DFS(vector<list<int>>& adjList, int node, vector<bool>& visited, 
    vector<bool>& visitedInThisTraversal, vector<int>& ans)
    {
        if(visited[node])
            return false;
        visited[node] = true;
        visitedInThisTraversal[node] = true;
        
        for(auto neigh : adjList[node])
            if(visitedInThisTraversal[neigh] || DFS(adjList, neigh, visited, visitedInThisTraversal, ans))
                return true;
                
        ans.push_back(node);
        visitedInThisTraversal[node] = false;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<int> ans;
        vector<int> inDeg(numCourses, 0);
        vector<list<int>> adjList = makeGraph(numCourses, inDeg, prerequisites);
        
        // BFS
        // queue<int> q;
        // for(int i = 0; i < inDeg.size(); i++)
        //     if(inDeg[i] == 0)
        //         q.push(i);
                
        // while(!q.empty())
        // {
        //     int fromNode = q.front();
        //     q.pop();
        //     ans.push_back(fromNode);
        //     for(auto toNode:adjList[fromNode])
        //     {
        //         inDeg[toNode]--;
        //         if(inDeg[toNode] == 0)
        //             q.push(toNode);
        //     }
        // }
        
        // return ans.size() == numCourses ? ans : vector<int>();
        
        // DFS
        vector<bool> visited(numCourses, false);
        vector<bool> visitedInThisTraversal(numCourses, false);
        for(int i = 0; i < numCourses; i++)
            if(!visited[i] && DFS(adjList, i, visited, visitedInThisTraversal, ans))
                return vector<int>();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> pre = {{{1,0},{2,0},{3,1},{3,2}}};
    // vector<pair<int, int>> pre = {};
    vector<int> ans = s.findOrder(4, pre);
    for(auto i:ans)
        LOG1(i);
    LOG2("");
    return 0;
}