/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class solution{
public:
	int maxProfit(vector<int>& price){
		if(price.size()<2) return 0;
		int n = price.size();
		vector<int> f(n,0);
		vector<int> g(n,0);

		for(int i =1,valley = price[0];i<n;i++){
			valley = min(valley,price[i]);
			f[i] = max(f[i-1],price[i]-valley);
		}
		for(int i = n-2,peak = price[i];i>=0;i--){
			peak = max(peak,price[i]);
			g[i] = max(g[i],peak-price[i]);
		}

		int max_profit = 0;
		for(int i =0;i<n;i++){
			max_profit = max(max_profit,f[i]+g[i]);
		}

		return max_profit;
	}
}