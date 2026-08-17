class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;

        int i = 0;

        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                digit = true;
            } else if (s[i] == '.') {
                if (exp || dot) {
                    return false;
                } else {
                    dot = true;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (exp || !digit || i + 1 == s.size()) {
                    return false;
                } else if (s[i + 1] == '+' || s[i + 1] == '-') {
                    i++;
                }
                digit = false;
                exp = true;
            } else {
                return false;
            }

            i++;
        }

        return digit;
    }
};