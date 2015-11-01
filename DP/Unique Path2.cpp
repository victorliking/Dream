/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]||grid[m-1][n-1]) return 0;
        vector<int> f(n,0);
        f[0]=1;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                f[j]= grid[i][j]?0:(j==0?0:f[j-1])+f[j];
            }
        }
        return f[n-1];
    }
};