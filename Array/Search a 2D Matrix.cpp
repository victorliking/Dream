/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int first =0 , last = matrix.size()*matrix[0].size()-1;
        int n = matrix[0].size();
        while(first<=last){
            int mid = (first+last)/2;
            int val = matrix[mid/n][mid%n];
            if(val==target) return true;
            else if (val<target) first = mid+1;
            else last = mid-1;
        }
        return false;
    }
};