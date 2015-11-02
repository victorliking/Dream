/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class BSTIterator {
	stack<TreeNode*> cache;
public:
    BSTIterator(TreeNode *root) {
       pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !cache.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = cache.top();
        cache.pop();
        pushAll(temp->right);
        return temp->val;
    }

    void pushAll(TreeNode* root){
    	for(;root!=NULL;root=root->left) cache.push(root);
    }
};
