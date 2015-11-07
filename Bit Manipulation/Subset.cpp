/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret,path,0,nums);
        return ret;
    }
    
    void dfs(vector<vector<int>>&ret, vector<int>&path,int step, vector<int>&nums){
        if(step==nums.size()){
            ret.push_back(path);
            return;
        }
        dfs(ret,path,step+1,nums);
        path.push_back(nums[step]);
        dfs(ret,path,step+1,nums);
        path.pop_back();
    }
};