/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> f(s.size()+1,false);
        f[0] = true;
        vector<vector<bool>> prev(s.length()+1,vector<bool>(s.length()));
        for(int i = 1;i<=s.length();i++){
            for(int j = i-1;j>=0;j--){
                if(f[j]&&wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    f[i] = true;
                    prev[i][j] =true;
                }
            }
        }
        vector<string> result;
        vector<string> path;
        
        gen(s,prev,s.length(),path,result);
        return result;
    }
    
    void gen(string &s, vector<vector<bool>>& prev,int cur, vector<string>& path, vector<string>& result){
        if(cur==0){
            string temp;
            for(auto iter = path.crbegin();iter!=path.crend();++iter){
                temp += *iter + " ";
            }
            temp.resize(temp.size()-1);
            result.push_back(temp);
        }
        for(int i =0;i<s.size();i++){
            if(prev[cur][i]){
                path.push_back(s.substr(i,cur-i));
                gen(s,prev,i,path,result);
                path.pop_back();
            }
        }
    }
};