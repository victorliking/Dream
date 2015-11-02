/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> ret;
		stack<TreeNode*> stk;
		while(1){
			while(root){
				stk.push(root);
				root=root->left;
			}
			if(stk.empty())break;
			root = stk.top();
			stk.pop();
			ret.push_back(root->val);
			root = root->right;
		}
		return ret;
	}
};