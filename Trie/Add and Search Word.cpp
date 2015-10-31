/*
Add and Search Word - Data structure design

The general idea is use the trie tree here 
Very important data structure doing serach

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

*/


class TrieNode{
    public: 
        bool flag =false;
        TrieNode* child[26];
};
class WordDictionary {
public:
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* index =root;
        TrieNode* temp;
        for(int i =0;i<word.length();i++){
            temp = index->child[word[i]-'a'];
            if(temp==nullptr) index->child[word[i]-'a'] = new TrieNode();
            index = index->child[word[i]-'a'];
        }
        index->flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word){
        return helper(word.c_str(),root);
    }
    bool helper(const char* word, TrieNode* root) {
         //int i =0;
        TrieNode* index = root;
        int i =0;
        for(i =0;word[i];i++){
            if(index&&word[i]!='.'){
                index = index->child[word[i]-'a'];
            }
            else if (index&&word[i]=='.'){
                TrieNode* temp = index;
                for(int j=0;j<26;j++){
                    index = temp->child[j];
                    if(helper(word+i+1,index))
                        return true;
                }
            }
            else break;
        }
        return index&&index->flag;
    }
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");