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
    std::vector<int> plusOne(std::vector<int>& digits) 
    {
        if(digits[digits.size()-1] != 9)
        {
            digits[digits.size()-1]++;
            return digits;
        }
        
        std::vector<int> digitsPlusOne;
        int carry = 1;
        digits[digits.size()-1] = 0;
        for(int i = digits.size()-2; i >= 0; --i)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            if(!carry)
                return digits;
        }
        if(carry)
        {
            // digits.push_back(carry);
            // int n = digits.size();
            // for(int i = digits.size()-1; i >= 1; --i)
            // {
            //     digits[i] = digits[i-1];
            // }
            // digits[0] = carry;
            digits.insert(digits.begin(), carry);
            return digits;
        }
            
    }
};

int main()
{
    Solution s;
    std::vector<int> digits = {9,9,9};
    std::vector<int> digitsPlusOne = s.plusOne(digits);
    for(auto i:digitsPlusOne)
        LOG1(i);
    LOG2("");
    return 0;
}