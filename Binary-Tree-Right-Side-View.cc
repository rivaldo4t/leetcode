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
    std::vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> ans;
        if(root == NULL)
            return ans;
        
        std::deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty())
        {
            int size = queue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = queue.front();
                if(i == size-1) // take the last element at each level
                    ans.push_back(temp->val);
                if(temp->left)
                    queue.push_back(temp->left);
                if(temp->right)
                    queue.push_back(temp->right);
                queue.pop_front();
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
    head->right = new TreeNode(5);
    
    std::vector<int> ans = s.rightSideView(head);
    for(auto i:ans)
        LOG1(i);
    LOG2("");
    
    return 0;
}