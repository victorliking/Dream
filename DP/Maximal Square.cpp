/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret =0;
        for(int i =0;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                int a =(i&&j)?matrix[i-1][j-1]:0;
                int b = i?matrix[i-1][j]:0;
                int c= j?matrix[i][j-1]:0;
                matrix[i][j]=matrix[i][j]>'0'?(min(a,min(b,c)))+1:0;
                ret = max(ret,matrix[i][j]*matrix[i][j]);
            }
        }
        return ret;
    }
};


