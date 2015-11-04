/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
*/

class Solution{
public:
	string fractionToDecimal(int n, int d) {
		iif(!numerator) return "0";
        long long num = (long long) numerator;
        long long deno = (long long) denominator;
        string ret = (num<0^deno<0)?"-":"";
        num = labs(num);
        deno = labs(deno);
        ret += to_string(num/deno);
        long long re = num%deno;
        if(re==0) return ret;
        ret+='.';
        int pos = ret.size();
        unordered_map<int,int> map;
        while(re&&map.find(re)==map.end()){
            map[re] = pos++;
            ret += '0'+re*10/deno;
            re = re*10%deno;
        }
        if(re){
            ret += ')';
            ret.insert(ret.begin()+map[re],'(');
        }
        return ret;
	}
};