/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
        
    }
};