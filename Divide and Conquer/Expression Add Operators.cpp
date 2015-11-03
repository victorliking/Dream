/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

class Solution{
public:
	vector<string> addOperators(string num, int target) {
        vector<string> result;
        addOperators(result, num, "", 0, 0, target);
        return result;
    }

    void addOperators(vector<string>& result, string nums, string t, long long last, long long curVal, int target) {
    	if(nums.length()==0){
    		if(curVal==target){
    			result.push_back(t);
    		}
    		return;
    	}
    	for(int i =1;i<=nums.length();i++){
    		string num = nums.substr(0,i);
    		if(num.length()>1&&num[0]=='0') return;
    		string nextNum = nums.substr(i);
    		if(t.length>0){
    			addOperators(result,nextNum,t+"+"+num,stoll(num),curVal+stoll(num),target);
    			addOperators(result,nextNum,t+"-"+num,-stoll(num),curVal-stoll(num),target);
    			addOperators(result,nextNum,t+"*"+num,last*stoll(num),curVal-last+(last*stoll(num)),target);
    		}
    		else 
    			addOperators(result,nextNum,num,stoll(num),stoll(num),target);
    	}
    }
};