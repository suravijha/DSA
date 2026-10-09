class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int ans = 0;
        int open = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (open % 2) {
                    ans++;
                    open--;
                }

                open += 2;
            } else {
                open--;

                if (open < 0) {
                    ans += 1;
                    open = 1;
                }
            }
        }

        ans += open;
        return ans;
    }
};