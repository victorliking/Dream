/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.
*/

class Solution{
public:
	vector<vector<string>> groupString(vector<string>& strings){
		unordered_map<string,vector<string>> map;
		for(int i =0;i<strings.size();i++){
			string t = strings[i];
			int diff =t[0]-'a';
			for(int j = 0;j<t.size();j++){
				if(t[j]-'a'-diff>0) t[j] = t[j]-diff;
				else t[j] = t[j]+26-diff;
			}
			map[t].push_back(strings[i]);
		}
		vector<vector<string>> ret;
        ret.resize(map.size());
        int count = 0;
        for(auto c:map){
            sort(c.second.begin(),c.second.end());
            ret[count++] = c.second;
        }
        return ret;
	}
};