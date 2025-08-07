// LeetCode 498
// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int row = 0;
        int col = 0;
        bool up = true;
        int m = mat.size(), n = mat[0].size();
        while (ans.size() < m * n)
        {
            ans.push_back(mat[row][col]);
            if (up)
            {
                if (col == n - 1)
                {
                    row++;
                    up = false;
                }
                else if (row == 0)
                {
                    col++;
                    up = false;
                }
                else
                {
                    col++;
                    row--;
                }
            }
            else
            {
                if (row == m - 1)
                {
                    col++;
                    up = true;
                }
                else if (col == 0)
                {
                    row++;
                    up = true;
                }
                else
                {
                    col--;
                    row++;
                }
            }
        }
        return ans;
    }
};