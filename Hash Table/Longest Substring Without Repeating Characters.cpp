/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution{
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> last(256,-1);
		int max_len =0 ;
		int start =0;
		for(int i =0;i<s.size();i++){
			if(last[s[i]]>=start){
				max_len = max(max_len,i-start);
				start = last[s[i]]+1;
			}
			last[s[i]] = i;
		}
		return max(max_len,(int)s.size()-start);
	}
};