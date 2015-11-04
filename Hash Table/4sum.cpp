/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size()<4) return ret;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i =0;i<size;i++){
        	int target3 = traget - nums[i];
        	for(int j =i+1;j<size();j++){
        		int target2 = target3-nums[i];
        		int front = j+1;;
        		int end = size-1;
        		while(front<back){
        			if(nums[back]+nums[front]==target2){
        				vector<int> path(4,0);
        				path[0] = nums[i];
        				path[1] = nums[j];
        				path[2] = nums[front];
        				path[3] = nums[back];
        				while(front<back&&nums[front]==path[2]) front++;
        				while(front<back&&nums[back]==path[3]) back--;
        			}
        			else if (nums[front]+nums[back]<target2) front++;
        			else back--;
        		}
        		while(j+1<size&&nums[j]==nums[j+1]) j++;
        	}
        	while(i+1<size&&nums[i]==nums[i+1]) i++;
        }
        return ret;
    }
};