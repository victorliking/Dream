/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
      vector<int> nums(n,-1);
      for(int i =0;i<edges.size();i++){
          int x = find(nums,edges[i].first);
          int y = find(nums,edges[i].second);
          
          // if two vertices happen to be in the same set
          // then there's a cycle
          if(x==y) return false;
          
          nums[y]=x;
      }
      return edges.size()==n-1;
    }  
    
    int find(vector<int>& nums, int i){
        if(nums[i]==-1) return i;
        return find(nums,nums[i]);
    }
};