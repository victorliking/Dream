/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution{
public:
	int findMin(vector<int>& nums){
		int low = 0;
		int high = nums.size()-1;
		while(low<high){
			int mind = (low+high)/2;
			if(nums[mid]<nums[high]){
				high = mid;
			}
			else if (nums[mid]>nums[high]){
				low = mid+1;
			}
			else high--;
		}
		return nums[low];
	}
};
