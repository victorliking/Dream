/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution{
public:
	vector<vector<int>> combination(int k ,int n){
		vector<vector<int>> ret;
		vector<int> path;
		dfs(ret,path,k,n);
		return ret;
	}

	void dfs(vector<vector<int>>&ret, vector<int>&path, int k ,int n){
		if(path.size()==k&&n==0){
			ret.push_back(path);
			return;
		}
		if(path.size()<k){
			for(int i = path.empty()?1:path.back()+1;i<=9;i++){
				path.push_back(i);
				dfs(ret,path,k,n-i);
				path.pop_back();
			}
		}
	}
};