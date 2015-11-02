/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
*/

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        stack<int> s1;
        stack<int> s2;
        inorder(root,target,false,s1);
        inorder(root,target,true,s2);

        while(k-- >0){
            if(s1.empty()) ret.push_back(s2.top()),s2.pop();
            else if (s2.empty()) ret.push_back(s1.top()),s1.pop();
            else if (abs(s1.top()-target)<abs(s2.top()-target))
                ret.push_back(s1.top()),s1.pop();
            else 
                ret.push_back(s2.top()),s2.pop();
        }
        return ret;
    }

    void inorder(TreeNode* root, double target, bool re, stack<int>&stk){
        if(root==nullptr) return;
        inorder(reverse?root->right:root->left,target,reverse,stk);
        stk.push(root->val);
        inorder(reverse?root->left:root->right,target,reverse,stk);
    }

};