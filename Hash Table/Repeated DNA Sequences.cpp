/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution{
public:
	vector<string> findRepeatedDnaSequences(string s){
		unordered_map<int,int>map;
		hash<string> hash;
		vector<string> ret;
		if(s.size()<9) return ret;
		for(int i =0;i<s.size()-9;i++){
			if(map[hash(s.substr(i,10))]++==1){
				ret.push_back(s.substr(i,10));
			}
		}
		return ret;
	}
};