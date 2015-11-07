/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution{
public:
	vector<vector<int>> combination(vector<int>& candidate, int target){
		vector<vector<int>> ret;
		vector<int> path;
		if(candidate.empty()) return ret;
		sort(candidate.begin(),candidate.end());
		helper(candidate,ret,path,target,0);
		return ret;
	}

	void helper(vector<int>&candidate, vector<vector<int>>& ret, vector<int>& path, int gap, int start){
		if(gap==0){
			ret.push_back(path);
			return ;
		}
		for(int i =start;i<candidate.size();i++){
			if(candidate[i]>gap) return;
			path.push_back(candidate[i]);
			helper(candidate,ret,path,gap- candidate[i],i);
			path.pop_back();
		}
	}
};