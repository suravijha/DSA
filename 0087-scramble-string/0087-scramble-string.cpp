class Solution {
private:
    bool solve(string& s1, string& s2, int i, int j, int len,
               vector<vector<vector<int>>>& dp) {

        if (len == 1) {
            return s1[i] == s2[j];
        }

        if (dp[i][j][len] != -1) {
            return dp[i][j][len];
        }

        for (int k = 1; k < len; k++) {

            if (solve(s1, s2, i, j, k, dp) &&
                solve(s1, s2, i + k, j + k, len - k, dp)) {

                dp[i][j][len] = 1;
                return true;
            }

            if (solve(s1, s2, i, j + len - k, k, dp) &&
                solve(s1, s2, i + k, j, len - k, dp)) {

                dp[i][j][len] = 1;
                return true;
            }
        }

        dp[i][j][len] = 0;
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        int n = s1.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n, vector<int>(n + 1, -1))
        );

        return solve(s1, s2, 0, 0, n, dp);
    }
};