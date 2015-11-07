/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution{
	vector<int> singleNumber(vector<int>& nums) {
	int diff = accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
	diff&=-diff;

	vector<int> ret = {0,0};
	for(int num:nums){
		if(num&diff==0)
			ret[0]^=num;
		else 
			ret[1]^=num;
	}

	return ret;
	}
};