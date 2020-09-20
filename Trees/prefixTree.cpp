// autocomplete, word search, IP checker(longest prefix match), spell check

class TrieNode {
public:
    // Initialize your data structure here.
    bool isEnd;
    TrieNode *next[26];
    
    TrieNode() {
        isEnd = false;
        
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};
class Trie {
public:
          
    /** Initialize your data structure here. */
    Trie() {
       root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr = root;
        for(auto &ch : word)
        {
            if(ptr -> next[ch - 'a'] == nullptr)
                ptr -> next[ch - 'a'] = new TrieNode();
            ptr = ptr -> next[ch - 'a'];
        }
            ptr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = root;
        for(auto &ch : word)
        {
            if(ptr -> next[ch - 'a'] == NULL)
                return false;
            
            ptr = ptr -> next[ch - 'a'];
        }
        if(ptr->isEnd) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for(auto &ch : prefix)
        {
            if(ptr -> next[ch - 'a'] == NULL)
                return false;
            
            ptr = ptr -> next[ch - 'a'];
        }
        return true;
        
    }
    private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
