/*

Implement a trie with insert, search, and startsWith methods.

*/

class TrieNode {
public:
    bool flag = false;
    TrieNode *child[26];
    // Initialize your data structure here.
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* start = root;
        TrieNode* temp;
        for(int i =0;i<word.length();i++){
            temp = start->child[word[i]-'a'];
            if(temp==nullptr){
                start->child[word[i]-'a'] = new TrieNode();
            }
            start = start->child[word[i]-'a'];
        }
        start->flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* start = root;
        TrieNode* temp;
        int i ;
        for( i =0;i<word.length();i++){
            temp = start->child[word[i]-'a'];
            if(temp==nullptr) break;
            start = start->child[word[i]-'a'];
        }
        if(i==word.size()&&start->flag) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* start = root;
        TrieNode* temp;
        for(int i =0;i<prefix.length();i++){
            temp = start->child[prefix[i]-'a'];
            if(temp==nullptr) return false;
            start = start->child[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

