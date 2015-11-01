/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root,nullptr,nullptr);
    }
    bool check(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root==nullptr) return true;
        if((max&&max->val<=root->val)||(min&&min->val>=root->val)) return false;
        return check(root->left,min,root)&&check(root->right,root,max);
    }
};