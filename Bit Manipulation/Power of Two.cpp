/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution{
public:
	bool isPowerTwo(int n ){
		if(n<=0) return false;
		return !(n&(n-1));
	}
};