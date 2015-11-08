/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;
        int beginX =0,endX= matrix[0].size()-1;
        int beginY =0, endY = matrix.size()-1;
        while(1){
            for(int  i =beginX;i<=endX;i++)  ret.push_back(matrix[beginY][i]);
            if(++beginY>endY) break;
            for(int i = beginY;i<=endY;i++) ret.push_back(matrix[i][endX]);
            if(--endX<beginX) break;
            for(int i = endX;i>=beginX;i--) ret.push_back(matrix[endY][i]);
            if(--endY<beginY) break;
            for(int i  =endY;i>=beginY;i--) ret.push_back(matrix[i][beginX]);
            if(++beginX>endX) break;
        }
        return ret;
    }
};