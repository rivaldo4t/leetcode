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

struct Complex
{
    int real;
    int imag;
    Complex(int x, int y) : real(x), imag(y) {}
};

class Solution 
{
public:
    string complexNumberMultiply(string a, string b) 
    {
        Complex ac(1, 1), bc(1, 1);
        
        int t = 0;
        while(a[t] != '+')
            t++;
        int r = stoi(a.substr(0, t));
        int i = stoi(a.substr(t+1, a.size()-t-2));
        ac = {r, i};
        
        LOG2(ac.real);
        LOG2(ac.imag);
        
        t = 0;
        while(b[t] != '+')
            t++;
        r = stoi(b.substr(0, t));
        i = stoi(b.substr(t+1, b.size()-t-2));
        bc = {r, i};
        
        LOG2(bc.real);
        LOG2(bc.imag);
        
        Complex cc (ac.real * bc.real - ac.imag * bc.imag, ac.real * bc.imag + ac.imag * bc.real);
        return to_string(cc.real) + "+" + to_string(cc.imag) + "i";
    }
};

int main()
{
    Solution s;
    LOG2(s.complexNumberMultiply("-1+2i", "3+-4i"));
    return 0;
}