/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

class Solution{
	public:
    bool isBalanced(TreeNode* root) {
        return height(root)>=0;
    }
    
    int height(TreeNode* root){
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(left<0||right<0||abs(left-right)>1) return -1;
        return 1+max(left,right);
    }
};