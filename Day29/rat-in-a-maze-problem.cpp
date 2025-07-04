/* Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).
The matrix contains only two possible values:
0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.
Note: Return the final result vector in lexicographically smallest order.*/

class Solution
{
private:
    bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &maze)
    {
        if (x < 0 || x >= n)
            return false;
        if (y < 0 || y >= n)
            return false;
        if (maze[x][y] == 0 || visited[x][y] == 1)
            return false;
        return true;
    }
    void solve(vector<vector<int>> &maze, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        // down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('D');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('L');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('R');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('U');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        // code here
        vector<string> ans;
        int srcx = 0;
        int srcy = 0;
        vector<vector<int>> visited = maze;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(maze, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};