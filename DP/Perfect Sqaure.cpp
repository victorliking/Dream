/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class solution{
public:
	int numSquares(int n){
		if(n<=0) return 0;
		vector<int> count({0});
		while(count.size()<=n){
			int m = count.size();
			int cntSquare = INT_MAX;
			for(int i =1;i*i<=m;i++){
				cntSquare = min(cntSquare,count[m-i*i]+1);
			}
			count.push_back(cntSquare);
		}
		return count[n];
	}
};