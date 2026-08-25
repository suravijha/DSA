class Solution {
private:
    int rows, cols;

    int solve(vector<vector<int>>& grid, int r, int c, int target) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == -1) {
            return 0;
        }

        if (grid[r][c] == 2) {
            return target == 0;
        }

        if (grid[r][c] == 0) {
            target--;
        }

        int original = grid[r][c];

        grid[r][c] = -1;

        int count = 0;

        count += solve(grid, r + 1, c, target);
        count += solve(grid, r - 1, c, target);
        count += solve(grid, r, c + 1, target);
        count += solve(grid, r, c - 1, target);

        grid[r][c] = original;

        return count;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int target = 0;
        pair<int, int> start;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 0)
                    target++;

                if (grid[i][j] == 1)
                    start = {i, j};
            }
        }

        return solve(grid, start.first, start.second, target);
    }
};