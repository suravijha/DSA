// LeetCode 59
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n));
        int startRow = 0;
        int startCol = 0;
        int endRow = n - 1;
        int endCol = n - 1;
        int count = 1;
        while (count <= n * n)
        {
            for (int i = startCol; i <= endCol; i++)
            {
                ans[startRow][i] = count;
                count++;
            }
            startRow++;
            for (int i = startRow; i <= endRow; i++)
            {
                ans[i][endCol] = count;
                count++;
            }
            endCol--;
            for (int i = endCol; i >= startCol; i--)
            {
                ans[endRow][i] = count;
                count++;
            }
            endRow--;
            for (int i = endRow; i >= startRow; i--)
            {
                ans[i][startCol] = count;
                count++;
            }
            startCol++;
        }
        return ans;
    }
};