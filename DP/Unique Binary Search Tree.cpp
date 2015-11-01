/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return generate(1,0);
        else return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> ret;
        if(start>end){
            ret.push_back(nullptr);
            return ret;
        }
        for(int k = start;k<=end;k++){
            vector<TreeNode*> left = generate(start,k-1);
            vector<TreeNode*> right = generate(k+1,end);
            for(auto i :left){
                for(auto j:right){
                    TreeNode* root = new TreeNode(k);
                    root->left = i;
                    root->right = j;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};