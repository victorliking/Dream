/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
       string ret,temp;
       vector<string> stk;
       stringstream ss(path);
       while(getline(ss,temp,'/')){
       	if(temp==""||temp=='.') continue;
       	if(temp==".."&&!stk.empty()) stk.pop_back();
       	else if(temp!="..") stk.push_back(temp);
       }
       for(auto str:stk) res+="/"+str;
       return res.empty()?"/":res;
    }   
};