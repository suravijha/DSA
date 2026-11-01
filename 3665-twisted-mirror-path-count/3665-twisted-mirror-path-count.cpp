class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> arr(n, vector<long long>(2, 0));
        arr[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        arr[j][0] = (arr[j][0] + arr[j][1]) % MOD;
                    } else {
                        arr[j][0] = arr[j][1];
                    }
                }

                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        arr[j][1] = (arr[j - 1][0] + arr[j - 1][1]) % MOD;
                    } else {
                        arr[j][1] = arr[j - 1][0];
                    }
                }
            }
        }

        return (arr[n - 1][0] + arr[n - 1][1]) % MOD;
    }
};