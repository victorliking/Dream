/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/
class Solution{
public:
	int sum;
	int maxPathSum(TreeNode* root){
		sum = INT_MIN;
		pathSum(root);
		return sum;
	}


	int pathSum(TreeNode* root){
		if(!root) return 0;
		int left = max(0,pathSum(root->left));
		int right = max(0,pathSum(root->right));
		sum = max(sum,left+right+root->val);
		return max(left,right)+root->val;
	}
};
