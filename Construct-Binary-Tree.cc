#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:

    //pre and in
    void printInorder(TreeNode* node)
    {
        if (node == NULL)
            return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    }

    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int preorder_index, 
                    int inorder_low, int inorder_high) 
    {
        if(inorder_low > inorder_high)
            return NULL;
            
        TreeNode* root = new TreeNode(preorder[preorder_index]);
        
        if(inorder_low == inorder_high)
            return root;
            
        int i=0;
        while(inorder[i] != root->val)
            i++;
        
        root->left = recur(preorder, inorder, preorder_index + 1, inorder_low, i-1);
        root->right = recur(preorder, inorder, preorder_index + (i-inorder_low) + 1, i+1, inorder_high);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return recur(preorder, inorder, 0, 0, inorder.size()-1);
    }
    
    //post and in
    void printPostOrder(TreeNode* node)
    {
        if (node == NULL)
            return;
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->val << " ";
    }
    
    TreeNode* recur2(vector<int>& postorder, vector<int>& inorder, int postorder_index, 
                    int inorder_low, int inorder_high) 
    {
        if(inorder_low > inorder_high)
            return NULL;
            
        TreeNode* root = new TreeNode(postorder[postorder_index]);
        
        if(inorder_low == inorder_high)
            return root;
            
        int i=0;
        while(inorder[i] != root->val)
            i++;
        
        root->left = recur2(postorder, inorder, postorder_index + (inorder_high - i) + 1, inorder_low, i-1);
        root->right = recur2(postorder, inorder, postorder_index + 1, i+1, inorder_high);
        
        return root;
    }

    TreeNode* buildTree2(vector<int>& postorder, vector<int>& inorder) 
    {
        return recur2(postorder, inorder, 0, 0, inorder.size()-1);
    }
};

int main()
{
    Solution s;
    
    vector<int> pre  = {1, 2, 3, 4};
    vector<int> in   = {2, 1, 3, 4};
    vector<int> post = {2, 4, 3, 1};
    
    //pre and in
    //TreeNode* temp = s.buildTree(pre, in);
    //s.printInorder(temp);
    //cout << endl;
    
    //post and in
    reverse(post.begin(), post.end());
    TreeNode* temp = s.buildTree2(post, in);
    s.printPostOrder(temp);
    cout << endl;
    return 0;
}