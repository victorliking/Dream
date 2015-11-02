/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> nums;
      stack<TreeNode*> right;
      while(root){
      	nums.push_back(root->val);
      	if(root->right!=NULL) right.push(root->right);
      	root=root->left;
      	if(root==NULL&&!right.empty()){
      		root = right.top();
      		right.pop();
      	}
      }
      return nums;
    }
};