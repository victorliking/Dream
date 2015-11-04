/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution{
public:
	vector<int> findSubstring(string s, vector<string>& words){
		unordered_map<string,int> counts;
		for(string word:words)
			counts[word]++;
		int n = s.size(), num = words.size(),len = words[0];
		vector<int> index;
		for(int i =0;i<n - num*len+1;i++){
			unordered_map<string, int> seen;
			int j =0;
			for(;j<num;j++){
				string word  =s.substr(i+j*len,len);
				if(counts.find(word)!=counts.end()){
					seen[word]++
					if(seen[word]>counts[word]) break;
				}
				else break;
			}
			if(j==num) index.push_back(i);
		}
		return index;
	}
};