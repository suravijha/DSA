class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<long long> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (obstacleGrid[m - 1][i] == 1) 
                break;

            dp[i] = 1;
        }

        for (int i = m - 2; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 1) {
                dp[n - 1] = 0;
            }

            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] += dp[j + 1];
            }
        }

        return dp[0];
    }
};