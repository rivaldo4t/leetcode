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

class PairComparator
{
public:
    bool operator ()(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first || a.first == b.first && a.second < b.second;
    }
};

class Solution 
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        // 1.55 fucking percentile
        // priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparator> pq;
        // for(auto i:arr)
        // {
        //     pq.push({abs(i-x), i});
        //     if(pq.size() > k)
        //         pq.pop();
        // }
        
        // vector<int> ret;
        // while(!pq.empty())
        // {
        //     ret.push_back(pq.top().second);
        //     pq.pop();
        // }
        
        // sort(ret.begin(), ret.end());
        // return ret;
        
        // vector<int> ret;
        
        // get index such that arr[index] is closest to x
        //lulz; can be done using lower-bound
        // int low = 0, high = arr.size() - 1;
        // int mid;
        // while(low < high)
        // {
        //     mid = low + (high - low) / 2;
        //     if(x > arr[mid])
        //         low = mid + 1;
        //     else if(x < arr[mid])
        //         high = mid - 1;
        //     else
        //         break;
        // }
        // if(high < 0 || low >= arr.size())
        //     mid = 0; //bug; worked somehow
        // else if(low >= high)
        //     mid = abs(arr[low] - x) <= abs(arr[high] - x) ? low : high; 
        
        // low = mid - 1, high = mid + 1;
        // ret.push_back(arr[mid]);
        // k--;
        // while(k--)
        // {
        //     if(low >= 0 && abs(arr[low] - x) <= abs(arr[high] - x))
        //     {
        //         ret.insert(ret.begin(), arr[low]);
        //         low--;
        //     }
        //     else if(high < arr.size())
        //     {
        //         ret.push_back(arr[high]);
        //         high++;
        //     }
        // }
        
        // return ret;
        
        // int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        // int i = index - 1, j = index;
        // while(k--)
        // {
        //     if(i < 0 || (j < arr.size() && abs(arr[i] - x) > abs(arr[j] - x)))
        //         j++;
        //     else
        //         i--;
        // }
        // return vector<int>(arr.begin() + i + 1, arr.begin() + j );
        
        // don't know why does the code below work
        // comment from other post with similar approach - 
        // I binary-search for where the resulting elements start in the array. 
        // It’s the first index i so that arr[i] is better than arr[i+k] 
        // (with “better” meaning closer to or equally close to x). 
        // Then I just return the k elements starting there.
        int left = 0, right = arr.size() - k;
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid+k] - x) left = mid + 1; 
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ret = s.findClosestElements(arr, 4, -1);
    // vector<int> arr = {1, 8, 10, 22, 31, 32};
    // vector<int> ret = s.findClosestElements(arr, 2, 20);
    for(auto i:ret)
        LOG1(i);
    LOG2("");
    return 0;
}