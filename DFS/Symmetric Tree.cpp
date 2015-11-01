/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return check(root->left,root->right);
    }
    
    bool check(TreeNode* left, TreeNode* right){
        if(!left&&!right) return true;
        if(!left||!right) return false;
        return left->val==right->val&&check(left->left,right->right)&&check(left->right,right->left);
    }
};