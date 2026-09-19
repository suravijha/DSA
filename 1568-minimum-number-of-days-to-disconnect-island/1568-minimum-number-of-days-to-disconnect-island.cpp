class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int islands(vector<vector<int>> grid) {
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            dfs(grid, i + directions[k][0], j + directions[k][1]);
        }
    }

public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (islands(grid) != 1)
            return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                    
                grid[i][j] = 0;

                if (islands(grid) != 1)
                    return 1;

                grid[i][j] = 1;
            }
        }

        return 2;
    }
};