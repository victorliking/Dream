/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int p[m][n];
        p[0][0]= grid[0][0];
        
        for(int i =1;i<m;i++){
            p[i][0] = p[i-1][0]+grid[i][0];
        }
        
        for(int i =1;i<n;i++){
            p[0][i] = p[0][i-1]+grid[0][i];
        }
        
        for(int i=1;i<m;i++){
            for(int j =1;j<n;j++){
                p[i][j] = min(p[i-1][j],p[i][j-1])+grid[i][j];
            }
        }
        
        return p[m-1][n-1];
    }
};