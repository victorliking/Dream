/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/


class Solution{
public:
	vector<string> binaryTreePath(TreeNode* root){
		vector<string> ret;
		if(root!=NULL) helper(root,"",ret);
		return ret;
	}

	void helper(TreeNode* root,string path, vector<string>& ret){
		if(root->left==NULL&&root->right==NULL) ret.push_back(path+to_string(root->val));
		if(root->left!=NULL) helper(root->left,path+to_string(root->val)+"->",ret);
		if(root->right!=NULL) helper(root->right,path+to_string(root->val)+"->",ret);
	}
};