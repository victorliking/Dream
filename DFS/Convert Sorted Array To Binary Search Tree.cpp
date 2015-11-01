/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

class Solution{
public:
	TreeNode* sortArrayToBST(vector<int>& nums){
		return build(nums.begin(),nums.end());
	}

	TreeNode* build(vector<int>::iterator begin, vector<int>::iterator end){
		int len = distance(begin,end);
		if(len<=0) return NULL;
		auto mid = left+len/2;
		TreeNode* root = new TreeNode(*mid);
		root->left = build(begin,mid);
		root->right = build(mid+1,end);
		return root;
	}
};