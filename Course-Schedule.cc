#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution 
{
public:

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>> preq)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(auto i:preq)
            graph[i.second].insert(i.first);
        return graph;
    }

    vector<int> calc_inDeg(vector<unordered_set<int>> graph)
    {
        vector<int> inDeg(graph.size(), 0);
        for(auto i:graph)
            for(auto j:i)
                inDeg[j]++;
        return inDeg;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> inDeg = calc_inDeg(graph);
        
        for(int i = 0; i < numCourses; i++)
        {
            int j;
            for(j = 0; j < numCourses; j++)
                if(inDeg[j] == 0)
                    break;
            
            // if every node has some inDeg, there's a cycle
            if(j == numCourses)
                return false;
            
            inDeg[j] = -1;
            
            for(int k:graph[j])
                inDeg[k]--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> preq = {{0, 1}, {1, 0}};
    // preq.push_back(make_pair(0, 1));
    // preq.push_back(make_pair(1, 0));
    cout << s.canFinish(2, preq);
    return 0;
}