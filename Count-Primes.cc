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
public:
    int countPrimes(int n) 
    {
        // sieve of eratosthenes
        std::vector<bool> isPrime(n, true);
        
        for(int i = 2; i*i < n; i++)
        {
            if(isPrime[i])
            {
                for(int j = i*i; j < n; j += i)
                    isPrime[j] = false;
            }
        }
        
        int count = 0;
        for(int i = 2; i < n; i++)
            if(isPrime[i])
                count++;
        return count;
    }
};

int main()
{
    Solution s;
    LOG2(s.countPrimes(3));
    return 0;
}