// LeetCode 1910
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};