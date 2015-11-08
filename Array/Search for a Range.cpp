/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = find_left(nums,target);
        if(left==-1) return{-1,-1};
        else return {left,find_right(nums,target)};
    }
    
    int find_left(vector<int>&nums,int target){
        int left =0,right = nums.size()-1;
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<target) left = mid+1;
            else right = mid;
        }
        return nums[left]==target?left:-1;
    }
    
    
    int find_right(vector<int>&nums,int target){
        int left =0,right = nums.size()-1;
        while(left<right){
            int mid = (left+right)/2+1;
            if(nums[mid]>target) right = mid-1;
            else left = mid;
        }
        return right;
    }
    
    
};