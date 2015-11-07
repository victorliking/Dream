/*
Given an array of integers, every element appears three times except for one. Find that single one.
*/

class Solution{
public:
	int singleNumber(vector<int>& s){
		vector<int> t(32,0);
		int sz = s.size();
		int i,j,n;
		for(int i =0;i<sz;i++){
			n = s[i];
			for(int j =31;j>=0;j--){
				t[j] += n&1;
				n >>=1;
				if(n==0) break;
			}
		}
		int ret = 0;
		for(j=31;j>=0;j--){
			n = t[j]%3;
			if(n)
				ret |= 1<<(31-j);
		}
		return ret;
	}
};