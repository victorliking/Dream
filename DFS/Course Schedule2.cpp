/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

*/


class Solution{
public:
	 vector<int> findOrder(int num, vector<pair<int, int>>& pre) {
	 	vector<vector<int>> adj(num,vector<int>());
	 	for(int i =0;i<pre.size();i++){
	 		adj[pre[i].first].push_back(pre[i].second);
	 	}
	 	vector<int> flag(num,0);
	 	vector<int> ret;
	 	for(int i =0;i<num;i++){
	 		if(!check(adj,flag,i,ret)){
	 			vector<int> rett;
	 			return rett;
	 		}
	 	}
	 	return ret;
	 }

	 bool check(vector<vector<int>>&adj,vector<int>&flag,int node ,vector<int>&ret){
	 	if(flag[node]==-1) return false;
	 	if(flag[node]==1)  return true;
	 	flag[node] = -1;

	 	for(auto r:adj[node]){
	 		if(!check(adj,flag,r,ret)) return false;
	 	}
	 	ret.push_back(node);
	 	flag[node] = 1;
	 	return true;
	 }
};










