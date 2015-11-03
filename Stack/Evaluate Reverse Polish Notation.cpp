/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution{
public:
	int evalRPN(vector<string>& tokens) {
       stack<int> stk;
       for(auto s:tokens){
       	if(s.size()>1||isdigit(s[0])) stk.push(stoi(s));
       	else{
       		auto x2 = stk.top();stk.pop();
       		auto x1 = stk.top();stk.pop();
       		switch(s[0]){
       			case '+':x1+=x2;break;
       			case '-':x1-=x2;break;
       			case '*':x1*=x2;break;
       			case '/':x1/=x2;break;
       		}
       		stk.push(x1);
       	}
       }
       return stk.top();
    }

}