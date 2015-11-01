/*
Given preorder and inorder traversal of a tree, construct the binary tree.
*/


class Solution{
public:
	TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
		return build(preorder,0,preorder.size(),inorder,0,inorder.size());
	}

	TreeNode* build(vector<int>&pre,int i,int ii, vector<int>& in,int j,int jj){
		if(i>=ii&&j>=jj) return NULL;
		TreeNode* root = new TreeNode(pre[i]);
		int dis = find(in.begin()+j,in.end()+jj,pre[i])-in.begin()-j;
		root->left = build(pre,i+1,i+1+dis,in,j,j+dis);
		root->right = build(pre,i+1+dis,ii,in,j+dis+1,jj);
	}
};