/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

*/

class Solution{
public:
	vector<int> rightSideView(TreeNode* root){
		vector<int> ret;
		traverse(root,ret,0);
		return ret;
	}

	void traverse(TreeNode* root,vector<int>&ret, int level){
		if(root==NULL) return;
		if(ret.size()==level) ret.push_back(root->val);
		traverse(root->left,ret,level+1);
		traverse(root->right,ret,level+1);
	}
};