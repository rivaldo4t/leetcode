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
    void recur(vector<vector<int>>& M, vector<int>& visited, int i)
    {
        for(int j = 0; j < M.size(); ++j)
        {
            if(M[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                recur(M, visited, j);
            }
        }
    }
    
    
    int find(int i, vector<int>& parents)
    {
        // union-find naive
        // return parents[i] == i ? i : find(parents[i], parents);
        
        // union-find using rank and path compression
        if(i != parents[i])
            parents[i] = find(parents[i], parents);
        return parents[i];
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        // too space heavy and also not sure if correct approach; incomplete
        // vector<unordered_set<int>> set;
        // unordered_set<int> temp;
        // for(int i = 0; i < M.size(); ++i)
        // {
        //     temp.insert(i);
        //     for(int j = i+1; j < M[0].size(); ++j)
        //     {
        //         if(M[i][j] == 1)
        //             temp.insert(j);
        //     }
        //     set.push_back<temp>;
        // }
        
        // temp.clear();
        // vector<unordered_set<int>> set2;
        
        // for(int i = 0; i < set.size()-1; i++)
        // {
        //     bool flag = false;
        //     for(auto j:set[i])
        //     {
        //         for(auto k:set[i+1])
        //         {
        //             if(j == k)
        //                 flag = true;
        //         }
        //     }
        //     if(flag)
        //     {
        //         temp = set[i];
        //         for(auto k:set[i+1])
        //             temp.insert(k);
                    
        //     }
        // }
        
        // dfs
        // vector<int> visited(M.size(), 0);
        // int count = 0;
        // for(int i = 0; i < M.size(); ++i)
        // {
        //     if(visited[i] == 0)
        //     {
        //         recur(M, visited, i);
        //         count++;
        //     }
        // }
        // return count;
        
        // union-find naive
        // int n = M.size();
        // vector<int> parents(n, 0);
        // for(int i = 0; i < n; ++i)
        //     parents[i] = i;
            
        // int numCircle = n;
        
        // for(int i = 0; i < n; ++i)
        // {
        //     for(int j = i+1; j <n; ++j)
        //     {
        //         if(M[i][j] == 1)
        //         {
        //             int parent1 = find(i, parents);
        //             int parent2 = find(j, parents);
        //             if(parent1 != parent2)
        //             {
        //                 parents[parent2] = parent1;
        //                 numCircle--;
        //             }
        //         }
        //     }
        // }
        // return numCircle;
        
        // union-find using rank and path compression
        int n = M.size();
        vector<int> parents(n, 0);
        vector<int> rank(n, 0);
        for(int i = 0; i < n; ++i)
            parents[i] = i;
            
        int numCircle = n;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                if(M[i][j] == 1)
                {
                    int parent1 = find(i, parents);
                    int parent2 = find(j, parents);
                    if(parent1 != parent2)
                    {
                        if(rank[parent1] > rank[parent2])
                            parents[parent2] = parent1;
                        else if(rank[parent1] < rank[parent2])
                            parents[parent1] = parent2;
                        else
                        {
                            parents[parent2] = parent1;
                            rank[parent1]++;
                        }
                        numCircle--;
                    }
                }
            }
        }
        return numCircle;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> M = {{1,1,0},{1,1,0},{0,0,1}};
    LOG2(s.findCircleNum(M));
    return 0;
}