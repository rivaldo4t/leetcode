#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode()
    {
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};

class Trie
{
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* ptr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(ptr->next[word[i]-'a'] == NULL)
                ptr->next[word[i]-'a'] = new TrieNode();
            ptr = ptr->next[word[i]-'a'];
        }
        ptr->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* ptr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(ptr->next[word[i]-'a'] == NULL)
                return false;
            ptr = ptr->next[word[i]-'a'];
        }
        return ptr &&  ptr->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode* ptr = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(ptr->next[prefix[i]-'a'] == NULL)
                return false;
            ptr = ptr->next[prefix[i]-'a'];
        }
        return ptr != NULL;
    }
};

int main()
{
    Trie* obj = new Trie();
    obj->insert("hello");
    bool param_2 = obj->search("hellow");
    bool param_3 = obj->startsWith("hellw");
    cout << param_2 << " " << param_3 << endl;
    return 0;
}