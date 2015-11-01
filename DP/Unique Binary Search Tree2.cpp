/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1);
        g[0] =1,g[1]=1;
        for(int i =2;i<=n;i++){
            for(int j =1;j<=i;j++){
                g[i] +=g[j-1]*g[i-j];
            }
        }
        return g[n];
    }
};