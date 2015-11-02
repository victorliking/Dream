/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        traverse(root,ret,1,true);
        return ret;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>&ret, int level, bool left){
        if(!root) return;
        if(level>ret.size()) ret.push_back(vector<int>());
        if(left) ret[level-1].push_back(root->val);
        else ret[level-1].insert(ret[level-1].begin(),root->val);
        
        traverse(root->left,ret,level+1,!left);
        traverse(root->right,ret,level+1,!left);
    }
};