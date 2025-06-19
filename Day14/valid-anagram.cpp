// LeetCode 242
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int scount[26] = {0};
        int tcount[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            scount[s[i] - 'a']++;
            tcount[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (scount[i] != tcount[i]) return false;
        }
        return true;
    }
};