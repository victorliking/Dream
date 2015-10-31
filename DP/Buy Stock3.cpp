/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class solution{
public:
	int maxProfit(int k ,vector<int>& prices){
		int size = prices.size();
		if(k==0||size<2) return 0;
		if(k>size/2){
			int sum =0;
			for(int i =1;i<size;i++){
				if(prices[i]>prices[i-1]){
					sum += prices[i]-prices[i-1];
				}
			}
			return sum;
		}

		vector<int> balace(k+1,INT_MIN);
		vector<int> profit(k+1,0);
		for(int i =0;i<size;i++){
			for(int j =1;j<=k;j++){
				balace[j] = max(balace[j-1]-prices[i],balace[j]);
				profit[j] = max(balace[j]+prices[i],profit[j]);
			}
		}
		return profit[k];
	}
}