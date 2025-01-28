#include<bits/stdc++.h>
class Node
{
    public:
    vector<Node*>links;
    bool flag;
    
    Node()
    {
        for(int i=0;i<26;i++)
        {
            links.push_back(NULL);
        }
        flag = false;
    }
    
    bool isContain(char ch)
    {
        if(links[ch-'a']!=NULL)
        {
            return true;
        }
        return false;
    }
    
    void put(char ch, Node* node1)
    {
        links[ch-'a'] = node1;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void setEnd()
    {
        flag = true;
    }
    
    bool isEnd()
    {
        if(flag==true) return true;
        else return false;
    }
};

class Trie {

private: 
    Node* root;    
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!(node->isContain(word[i])))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!(node->isContain(word[i])))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if(node->isEnd())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!(node->isContain(word[i])))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;      
    }
};
