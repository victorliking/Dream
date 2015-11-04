/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

class Solution{
public:
	bool isIsomorphic(string s, string t){
		int m[128] ={0}, n[128] = {0};
		int size= s.size();
		for(int i =0;i<size;i++){
			if(m[s[i]]!=n[t[i]]) return false;
			m[s[i]] = i+1;
			n[t[i]] = i+1;
		}
		return true;
	}
};