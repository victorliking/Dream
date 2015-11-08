/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,0,i,j,visited))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>&board,string&word,int index, int x,int y,vector<vector<bool>>&visited){
        if(index==word.size()) return true;
        if(x<0||x>=board.size()||y<0||y>=board[0].size()) return false;
        if(board[x][y]!=word[index]) return false;
        if(visited[x][y]) return false;
        
        visited[x][y]=true;
        
        bool ret = dfs(board,word,index+1,x+1,y,visited)||
                   dfs(board,word,index+1,x,y+1,visited)||
                   dfs(board,word,index+1,x-1,y,visited)||
                   dfs(board,word,index+1,x,y-1,visited);
        visited[x][y] = false;
        return ret;
    }
};