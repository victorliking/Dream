/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

class solution{
	void sortColors(vector<int>& nums){
		int red = 0,blue= nums.size()-1;
		for(int i =0;i<=blue;){
			if(nums[i]==0) swap(nums[i++],nums[red++]);
			else if(nums[i]==2) swap(nums[i],nums[blue--]);
			else i++;
		}
	}
};