/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        stack<int> s1;
        stack<int> s2;
        inorder(root,target,false,s1);
        inorder(root,target,true,s2);
        while(!s1.empty()) cout<<s1.top()<<' ',s1.pop();
        cout<<endl;
        while(!s2.empty()) cout<<s2.top()<<' ',s2.pop();
        //cout<<endl;
        while(k--){
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
        inorder(re?root->right:root->left,target,re,stk);
        if((re&&root->val<=target)||(!re&&root->val>target)) return;
        stk.push(root->val);
        inorder(re?root->left:root->right,target,re,stk);
    }
};