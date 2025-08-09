// LeetCode 557
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

class Solution {
private:
    void reverse(string &s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
public:
    string reverseWords(string s) {
        int start = 0;
        int n = s.size();
        int end = 0;
        while (start < n) {
            while (end < n && s[end] != ' ') {
                end++;
            }
            reverse(s, start, end - 1);
            end++;
            start = end;
        }
        return s;
    }
};