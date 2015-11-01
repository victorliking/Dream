/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution{
public:
	int maximumGap(vector<int>& nums){
		int n = nums.size();
		if(n<2) return 0;
		auto lu = minmax_element(nums.begin(),nums.end());
		int l = *lu.first, u = *lu.second;
		int gap = max((u-l)/(n-1),1);
		int m = (u-l)/gap+1;

		vector<vector<int>> buckets(m,{INT_MAX,INT_MIN});
		for(int num:nums){
			int k =(num-l)/gap;
			if(num<buckets[k][0]) buckets[k][0] = num;
			if(num>buckets[k][1]) buckets[k][1] = num;
		}
		int i =0,j;
		while(i<m){
			j = i+1;
			while(j<m&&buckets[j][0]==INT_MAX&&buckets[j][1]==INT_MIN) j++;
			if(j==m) break;
			gap = max(gap,buckets[j][0]-buckets[i][1]);
			i = j;
		}
		return gap;
	}
};