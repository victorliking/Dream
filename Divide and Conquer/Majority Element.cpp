/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.
*/

class Solution{
public:
	vector<int> majorityElement(vector<int>& nums) {
		int count1 =0;
		int count2 = 0;
		int a,b;
		for(int n :nums){
			if(count1==0||n==a){
				count1++;
				a = n;
			}
			else if(count2==0||n==b){
				count2++;
				b = n;
			}
			else {
				count1--;
				count2--;
			}
		}
		count1=count2=0;
		for(int n :nums){
			if(n==a) count1++;
			else if(n==b) count2++;
		}
		vector<int> ret;
        if(count1>nums.size()/3) ret.push_back(a);
        if(count2>nums.size()/3) ret.push_back(b);
        return ret;
	}
};