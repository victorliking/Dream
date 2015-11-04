/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

class Solution{
public:
	int lengthofString(string s){
		if(s.empty()) return 0;
		vector<int> dict(256,0);
		int count =0,len =1 ,start =0;
		for(int i =0;i<s.size();i++){
			dict[s[i]]++;
			if(dict[i]==1){
				count++;
				while(count>2){
					dict[s[start]]--;
					if(dict[s[start]]==0) count--;
					start++;
				}
			}
			if(i-start+1>len) len = i-start+i;
		}
		return len;
	}
};
