/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/


class solution{
public:
	int maxProfit(vector<int>& price){
		if(price.size()<2) return 0;
		int profit = 0;
		int min_price = price[0];
		for(int i =1;i<price.size();i++){
			min_price = min(min_price,price[i]);
			profit = max(profit,price[i]-min_price);
		}
		return profit;
	}
}