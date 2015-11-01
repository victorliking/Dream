/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

class Solution {
public:
	 void flatten(TreeNode* root) {
	 	if(!root) return;
	 	flatten(root->left);
	 	flatten(root->right);

	 	if(!root->left) return;

	 	TreeNode* p = root->left;
	 	while(p->right) p = p->right;
	 	p->right = root->right;
	 	root->right = root->left;
	 	root->left = nullptr;
	 }
};