/*
There are a row of n houses, each house can be painted with one of the k colors. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; 
costs[1][2] is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses.
*/


class solution{
public: 
	int minCost(vector<vector<int>>& costs){
		int n = costs.size();
		if(n==0) return 0;
		int k = costs[0].size();
		if(k==1) return costs[0][0];

		vector<int> dp(k,0);
		int min1 = 0,min2 = 0;

		for(int i =0;i<n;i++){
			int min1_old = min1;
			int min2_old = min2;
			min1 = INT_MAX;
			min2 = INT_MAX;
			for(int j =0;j<k;j++){
				if(dp[j]!=min1_old||min1_old==min2_old){
					dp[j] = min1_old+costs[i][j];
				}
				else{
					dp[j] = min2_old+costs[i][j];
				}

				if(min1<=dp[j]){
					min2 = min(min2,dp[j]);
				}
				else{
					min2 = min1;
					min1 = dp[j];
				}
			}
		}
		return min1;

	}
};