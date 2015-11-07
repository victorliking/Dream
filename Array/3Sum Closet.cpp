/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
		int result =0, min_gap = INT_MAX;
		sort(num.begin(),num.end());
		for(int i = 0;i<num.size()-1;i++){
			int j = i+1;
			int k = num.size()-1;
			while(j<k){
				int sum = num[i]+num[j]+num[k];
				int gap = abs(sum-target);
				if(gap<min_gap){
					min_gap = gap;
					result = sum;
				}
				if(sum<target) j++;
				else k--;
			}
		}
		return result;
	}
};