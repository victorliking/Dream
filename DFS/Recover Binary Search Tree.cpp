/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/


class Solution {
public:
    void recoverTree(TreeNode* root) {
        pre = first = second = NULL;
        inorder(root);
        if (first) {
            int temp = first -> val;
            first -> val = second -> val;
            second -> val = temp;
        }
    }
    
    private:
    TreeNode *first, *second, *pre;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root -> left);
        if (pre && pre -> val > root -> val) {
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        inorder(root -> right);
    } 
};