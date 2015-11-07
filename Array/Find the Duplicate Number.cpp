/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

*/

class Solution{
public:
	int findDuplicate(vector<int>&nums){
		int n = nums.size(),l=0,r=n-1;
		while(l<r){
			int m = l+((l-r)>>1);
			int cnt = noGreaterThan(nums,m);
			if(cnt<=m) l = m+1;
			else r = m;
		}
		return l;
	}

	int noGreaterThan(vector<int>&nums,int target){
		int cnt =0;
		for(int num:nums){
			if(nums<=target) cnt++;
		return cnt;
		}
	}
};