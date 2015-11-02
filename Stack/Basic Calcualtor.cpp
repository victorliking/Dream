/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/

class Solution{
public: 
	int calculate(string s){
		stack<int> t;
		t.push(1);
		int sum =0,temp =0, lastSign = 1;
		for(auto c:s){
			if(c=='(') t.push(lastSign);
			else if (c==')') t.pop();
			if(c>='0'&&c<='9'){
				temp = temp*10+c-'0';
			}
			if(c=='-'||c=='+'){
				sum+=lastSign*temp;
				temp =0;
				lastSign = (c=='-'?-1:1)*t.top();
			}
		}
		sum+=temp*lastSign;
		return sum;
	}
};