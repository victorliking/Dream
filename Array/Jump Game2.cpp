/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution{
public:
	int jump(vector<int>&nums){
		int n = nums.size(),step =0,start=0,end=0;
		while(end<n-1){
			step++;
			int maxend = end+1;
			for(int i =start;i<=end;i++){
				if(i+nums[i]>=n-1) return step;
			}
			start = end+1;
			end = maxend;
		}
		return step;
	}
};