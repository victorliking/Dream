/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

class solution{
public:
	void wiggleSort(vector<int>&nums){
		if(nums.size()<=1) return;
		bool inc = true;
		for(int i =1;i<nums.size();i++){
			if((inc&&nums[i-1]>nums[i])||(!inc&&nums[i-1]<nums[i]))
				swap(nums[i-1],nums[i]);
			inc = !inc;
		}
	}
};