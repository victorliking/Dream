/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/

class TrieNode{
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode(){
        is_end =false;
        children = vector<TrieNode*>(26,NULL);
    }
};

class Trie{
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>&words){
        root = new TrieNode();
        for(int i =0;i<words.size();i++){
            addWord(words[i]);
        }
    }
    
    void addWord(const string& word){
        TrieNode* cur = root;
        for(int i =0;i<word.size();i++){
           if(cur->children[word[i]-'a']==nullptr){
               cur->children[word[i]-'a'] = new TrieNode();
           }
           cur=cur->children[word[i]-'a'];
        }
        cur->is_end = true;
    }
private:
    TrieNode* root;
};



class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        set<string> ret;
        for(int i =0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                helper(board,i,j,root,"",ret);
            }
        }
        vector<string> result;
        for(auto it:ret) result.push_back(it);
        return result;
        
    }

    void helper(vector<vector<char>>&board,int x,int y, TrieNode*root,string word, set<string>& ret){
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]==' ')return;
        if(root->children[board[x][y]-'a']!=nullptr){
            word += board[x][y];
            root = root->children[board[x][y]-'a'];
            if(root->is_end) ret.insert(word);
            char c = board[x][y];
            board[x][y]=' ';
            helper(board,x+1,y,root,word,ret);
            helper(board,x-1,y,root,word,ret);
            helper(board,x,y-1,root,word,ret);
            helper(board,x,y+1,root,word,ret);
            board[x][y]=c;
        }
    }
};