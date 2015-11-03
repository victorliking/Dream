/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity
*/

class Solution{
public:
	bool verifyPreorder(vector<int>&preorder){
		int low = INT_MIN,i =-1;
		for(auto c:preorder){
			if(c<low) return false;
			while(i>=0&&c>preorder[i--])
				low = preorder[i--];
			preorder[i++] =c;
		}
		return true;
	}
};