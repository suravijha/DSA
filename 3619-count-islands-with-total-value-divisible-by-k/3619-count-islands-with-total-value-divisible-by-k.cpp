class Solution {
private:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    
    long long dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) {
            return 0;
        }

        long long sum = grid[r][c];

        grid[r][c] = 0;
        
        for (int i = 0; i < 4; i++) {
            sum += dfs(grid, r + dir[i][0], c + dir[i][1]);
        }

        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && (dfs(grid, i, j) % k == 0)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};