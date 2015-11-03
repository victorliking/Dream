/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution{
public:
	int findKthLargest(vector<int>&nums,int k){
		int cur = nums[k-1];
		vector<int> big;
		vector<int> small;
		for(int i =0;i<nums.size();i++){
			if(i==k-1) continue;
			else if (nums[i]>=cur) big.push_back(nums[i]);
			else small.push_back(nums[i]);
		}

		if(big.size()==k-1) return cur;
		else if (big.size()>k-1) return  findKthLargest(big,k);
		else return findKthLargest(small,k-big.size()-1);
	}
};