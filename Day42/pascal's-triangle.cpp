// LeetCode 118
// Given an integer numRows, return the first numRows of Pascal's triangle.

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int n = 0; n < numRows; n++)
        {
            vector<int> row;
            row.push_back(1);
            int val = 1;
            for (int k = 1; k <= n; k++)
            {
                val = val * (n - k + 1) / k;
                row.push_back(val);
            }
            ans.push_back(row);
        }
        return ans;
    }
};