/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/


class Solution{
public:
	bool isStrobogrammatic(string num){
		string t = num;
		unordered_map<char,char> map = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
	
		for(int i =0;i<t.size();i++){
			if(!map.count(num[i])) return false;
			t[i] = map[num[i]];
			if(t[i]!=num[num.size()-1-i]) return false;
		}
		return true;
		
	}
};