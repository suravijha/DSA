class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;

        int match = 0;
        int star = -1;

        int m = s.length();
        int n = p.length();

        while (i < m) {
            if (j < n && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                star = j;
                match = i;
                j++;
            } else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }

        while (j < n && p[j] == '*') {
            j++;
        }

        return j == n;
    }
};