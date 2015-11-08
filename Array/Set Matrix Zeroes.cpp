/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col_zero = false;
        bool row_zero = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i =0;i<m;i++){
            if(matrix[i][0]==0) {col_zero =true;break;}
        }
        for(int i =0;i<n;i++){
            if(matrix[0][i]==0) {row_zero = true;break;}
        }
        
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0,matrix[i][0]=0;
                }
            }
        }
        
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        
        if(col_zero){
            for(int i =0;i<m;i++) matrix[i][0] =0;
        }
        
         if(row_zero){
            for(int j =0;j<n;j++) matrix[0][j] =0;
        }
    }
};