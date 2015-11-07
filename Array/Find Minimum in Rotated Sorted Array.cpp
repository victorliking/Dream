/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution{
public:
	int findMin(vector<int>&nums){
		int start =0 ,end = nums.size()-1;
		while(start<end){
			if(nums[start]<nums[end]) return nums[start];
			int mid = (start+end)/2;
			if(nums[mid]>=nums[end])
				start = mid+1;
			else end = mid;
		}
		return nums[start];
	}
};