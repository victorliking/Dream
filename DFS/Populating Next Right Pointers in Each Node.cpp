/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/


class Solution {
public:
    void connect(TreeLinkNode *root) {
       if(root==NULL) return;
       TreeLinkNode dummy(-1);
       for(TreeLinkNode* cur =root,*prev=&dummy;cur;cur=cur->next){
    		if(cur->left!=NULL){
    			prev->next = cur->left;
    			prev = prev->next;
    		}
    		if(cur->right!=NULL){
    			prev->next = cur->right;
    			prev = prev->next;
    		}
       }
       connect(dummy.next);
    }
};