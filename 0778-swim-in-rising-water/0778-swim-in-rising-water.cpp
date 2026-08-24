class Solution {
private:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r, int c, int t) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid.size() || visit[r][c] || grid[r][c] > t) {
            return false;
        }

        if (r == grid.size() - 1 && c == grid.size() - 1) {
            return true;
        }

        visit[r][c] = true;
        
        return dfs(grid, visit, r + 1, c, t) ||
               dfs(grid, visit, r - 1, c, t) ||
               dfs(grid, visit, r, c + 1, t) ||
               dfs(grid, visit, r, c - 1, t);
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        int mini = grid[0][0];
        int maxi = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mini = min(mini, grid[i][j]);
                maxi = max(maxi, grid[i][j]);
            }
        }

        int l = mini;
        int r = maxi;

        while (l < r) {
            int m = (l + r) >> 1;

            if (dfs(grid, visit, 0, 0, m)) {
                r = m;
            } else {
                l = m + 1;
            }

            for (int row = 0; row < n; row++) {
                fill(visit[row].begin(), visit[row].end(), false);
            }
        }

        return r;
    }
};