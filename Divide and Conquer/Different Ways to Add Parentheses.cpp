/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        int size = input.size();
        for(int i =0;i<size;i++){
        	char c = input[i];
        	if(c=='+'||c=='-'||c=='*'){
        		vector<int> ret1 = diffWaysToCompute(input.substr(0,i));
        		vector<int> ret2 = diffWaysToCompute(input.substr(i+1));
        		for(auto n1:ret1){
        			for (auto n2:ret2){
        				if(c=='+') ret.push_back(n1+n2);
                        else if (c=='-') ret.push_back(n1-n2);
                        else ret.push_back(n1*n2);
        			}
        		}
        	}
        }
        if(ret.empty()){
        	ret.push_back(atoi(input.c_str()));
        }
        return ret;
    }
};