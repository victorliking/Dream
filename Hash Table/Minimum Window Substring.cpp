/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

cclass Solution {
public:
    string minWindow(string s, string t) {
       		if(s.empty()||s.size()<t.size())
			return "";
		vector<int> expCnt(256,0);
		vector<int> curCnt(256,0);

		int cnt =0;
		int start = 0;
		int minD = INT_MAX;
		int minS = 0;

		for(auto c :t){
			expCnt[c]++;
		}
		for (int i = 0; i < s.length(); ++i) {
            if (expCnt[s[i]] > 0) {
                curCnt[s[i]]++;
                if (curCnt[s[i]] <= expCnt[s[i]]) {  // Counting expected elements.
                    cnt++;
                }
            }
            if (cnt == t.size()) {  // If window meets the requirement.
                while (expCnt[s[start]] == 0 ||  // Adjust left bound of window.
                       curCnt[s[start]] > expCnt[s[start]]) {
                    --curCnt[s[start]];
                    ++start;
                }

                if (minD > i - start + 1) {  // Update minimum window.
                    minD = i - start + 1;
                    minS = start;
                }
            }
        }
		if(minD ==INT_MAX){
			return "";
		}
		return s.substr(minS,minD);
    }
};