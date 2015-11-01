/*
Given inorder and postorder traversal of a tree, construct the binary tree.
*/

class Solution{
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
		return build(inorder,0,inorder.size(),postorder,0,postorder.size());
	}

	TreeNode* build(vector<int>& in, int i ,int ii, vector<int>& pos, int j,int jj){
		if(i>=ii||j>=jj) return NULL;
		TreeNode* root = new TreeNode(pos[jj-1]);
		int dis = find(in.begin()+i,in.end()+ii,pos[jj-1])-in.begin()-i;
		root->left = build(in,i,i+dis,pos,j,j+dis);
		root->right = build(in,i+dis+1,ii,pos,j+dis,jj-1);
		return root;
	}
};