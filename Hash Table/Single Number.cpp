/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/

class Solution{
public:
	int singleNumber(vector<int>& nums){
		int x =0 ;
		for(int i=0;i<nums.size();i++){
			x^nums[i];
		}
		return x;
	}
};