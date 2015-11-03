/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


class Solution {
public:
    bool isValid(string s) {
        string left = "[{(";
        string right = "]})";
        stack<char> st;
        
        for(auto c:s){
            if(left.find(c)!=string::npos){
                st.push(c);
            }
            else{
                if(st.empty()||st.top()!=left[right.find(c)])
                    return false;
                else    
                    st.pop();
            }
        }
        return st.empty();
    }
};