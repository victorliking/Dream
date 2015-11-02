/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/
class Solution{
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> tovisit;
		TreeNode* curNode = root;
		TreeNode* lastNode = NULL;
		while(curNode||!tovisit.empty()){
			if(curNode){
				tovisit.push(curNode);
				curNode = curNode->left;
			}
			else{
				TreeNode* temp = tovisit.top();
				if(temp->right&&temp->right!=lastNode){
					curNode = temp;
				}
				else {
					ret.push_back(temp->value);
					lastNode = temp;
					tovisit.pop();
				}
			}
		}
		return ret;
	}
};
