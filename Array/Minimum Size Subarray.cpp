/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution{
public:
	int minSubArrayLen(int s, vector<int>&nums){
		int min_Length =INT_MAX, firstPos = 0, sum =0;
		for(int i =0;i<nums.size();i++){
			sum+=nums[i];
			while(sum>=s){
				min_Length = min(min_Length,i- firstPos+1);
				sum -= nums[firstPos++];
			}
		}
		return min_Length==INT_MAX?0:min_Length;
	}
};