#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#define LOG1(x) std::cout << x
#define LOG2(x) std::cout << x << std::endl

class Solution 
{
public:
    int minDistance(std::string word1, std::string word2) 
    {
        std::vector<std::vector<int>> dp (word1.size()+1, std::vector<int> (word2.size()+1, 0));
        
        for(int i = 0; i < dp.size(); i++)
            dp[i][0] = i;
        for(int i = 0; i < dp[0].size(); i++)
            dp[0][i] = i;
        
        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 1; j < dp[i].size(); j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    Solution s;
    LOG2(s.minDistance("poke", "make"));
    return 0;
}