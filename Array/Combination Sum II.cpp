/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution{
public:
	vector<vector<int>> combination2(vector<int>& candidates, int target){
		vector<vector<int>> ret;
		vector<int> path;
		sort(candidates.begin(),candidates.end());
		helper(candidates,ret,pat,target,0);
		return ret;
	}

	void helper(vector<int>& candidates, vector<vector<int>>&ret, vector<int>& path, int gap, int start){
		if(gap==0){
			ret.push_back(path);
			return;
		}
		int previous = -1;
		for(int i=start;i<candidates.size();i++){
			if(candidates[i]==previous) continue;
			if(candidates[i]>gap) return;
			previous = candidates[i];

			path.push_back(candidates[i]);
			helper(candidates,ret,path,gap-candidates[i],i+1);
			path.pop_back();
		}
	}
};