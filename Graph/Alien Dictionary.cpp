/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char>> suc;
        map<char, int> pre;
        set<char> chars;
        string s;
        for (string t : words) {
            chars.insert(t.begin(), t.end());
            for (int i=0; i<min(s.size(), t.size()); ++i) {
                char a = s[i], b = t[i];
                if (a != b) {
                    suc[a].insert(b);
                    ++pre[b];
                    break;
                }
            }
            s = t;
        }
        set<char> free = chars;
        for (auto ci : pre)
            free.erase(ci.first);
        string order;
        while (free.size()) {
            char a = *begin(free);
            free.erase(a);
            order += a;
            for (char b : suc[a])
                if (--pre[b] == 0)
                    free.insert(b);
        }
        return order.size() == chars.size() ? order : "";
    }
};