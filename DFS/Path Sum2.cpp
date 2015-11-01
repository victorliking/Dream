/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>> ret;
      vector<int> path;
      find(ret,path,root,sum);
      return ret;
    }

    void find(vector<vector<int>>& ret,vector<int>& path, TreeNode* root,int gap){
    	if(root==NULL) return;
    	path.push_back(root->val);
    	if(!root->left&&!root->right){
    		if(gap==root->val) ret.push_back(path);
    	}
    	find(ret,path,root->left,gap-root->val);
    	find(ret,path,root->right,gap-root->val);
    	path.pop_back();
    }
};