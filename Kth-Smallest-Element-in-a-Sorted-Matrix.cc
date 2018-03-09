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
    struct Mat
    {
        int x, y, val;
        Mat(int _x, int _y, int _val) : x(_x), y(_y), val(_val) {}
    };
    
    struct compFunc
    {
        bool operator ()(const Mat a, const Mat b)
        {
            return a.val > b.val;
        }
    };
    
    // doesn't work
    // bool compFunc (Mat a, Mat b)
    // {
    //     return a.val > b.val;
    // }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        // max Heap
        // add all elements from matrix and check for the kth smallest
        // priority_queue<int> pq;
        // for(auto i:matrix)
        // {
        //     for(auto j:i)
        //     {
        //         pq.push(j);
        //         if(pq.size() == k+1)
        //             pq.pop();
        //     }
        // }
        // return pq.top();
        
        // min Heap; faster than the one above
        // add elements only when required in sorted order
        // priority_queue<Mat, vector<Mat>, compFunc> pq;
        // for(int i = 0; i < matrix.size(); i++)
        //     pq.push({i, 0, matrix[i][0]});
            
        // while(k-- > 1)
        // {
        //     auto temp = pq.top();
        //     pq.pop();
        //     if(temp.y < matrix[0].size() - 1)
        //         pq.push({temp.x, temp.y + 1, matrix[temp.x][temp.y + 1]}); // push next element from corresponding row to pq
        // }
        
        // return pq.top().val;
        
        // Binary Search
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low < high)
        {
            int mid = low + (high-low)/2;
            int countNotGreaterThan = 0;
            for(int i = 0; i < n; i++)
            {
                countNotGreaterThan +=  upper_bound(matrix[i].begin(), 
                                        matrix[i].end(), mid) - 
                                        matrix[i].begin();
            }
            if(countNotGreaterThan < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix =    {   
                                        {1, 5, 9},
                                        {2, 7, 10},
                                        {4, 12, 15}
                                    };
    LOG2(s.kthSmallest(matrix, 6));
    return 0;
}