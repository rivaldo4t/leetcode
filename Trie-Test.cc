#include <iostream>
#include <vector>
#include <stack>
using namespace std;


typedef struct TrieNode
{
    bool wordEnd;
    struct TrieNode *letter[26];
}TrieNode;

TrieNode* getNode()
{
    TrieNode* N = new TrieNode;
    N->wordEnd = false;
    for(int i = 0; i < 26; i++)
        N->letter[i] = NULL;
    return N;
}

void insert(TrieNode* root, string k)
{
    TrieNode* ptr = root;
    
    for(int i = 0; i < k.length(); i++)
    {
        if(ptr->letter[k[i]-'a'] == NULL)
            ptr->letter[k[i]-'a'] = getNode();
        
        ptr = ptr->letter[k[i]-'a'];
    }
    ptr->wordEnd = true;
}

bool search(TrieNode* root, string k)
{
    TrieNode* ptr = root;
    
    for(int i = 0; i < k.length(); i++)
    {
        if(ptr->letter[k[i]-'a'] == NULL)
            return false;
            
        ptr = ptr->letter[k[i]-'a'];
    }
    return ptr && ptr->wordEnd;
}

bool isFree(TrieNode* root)
{
    for(int i = 0; i < 26; i++)
    {
        if(root->letter[i] != NULL)
            return false;
    }
    return true;
}

bool recur(TrieNode* root, string k, int level, int length)
{
    if(root == NULL)
        return false;
 
    if(level == length)
    {
        if(root->wordEnd)
        {
            root->wordEnd = false;
            if(isFree(root))
                return true;
        }
    }
    else
    {
        if(recur(root->letter[k[level] - 'a'], k, level + 1, length))
        {
            delete (root->letter[k[level] - 'a']);
            root->letter[k[level] - 'a'] = NULL;
            return (!root->wordEnd && isFree(root));
        }
    }
    
    return false;
}

void deletekey(TrieNode* root, string k)
{
    recur(root, k, 0, k.length());
}

int main()
{
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    TrieNode *root = getNode();
 
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    // search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    
    search(root, "there") ? cout << "Yes\n" : cout << "No\n";
    deletekey(root, "there");
    search(root, "there") ? cout << "Yes\n" : cout << "No\n";
    search(root, "their") ? cout << "Yes\n" : cout << "No\n";
    
    return 0;
}