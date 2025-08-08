// LeetCode 119
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        ans.push_back(1);
        long long val = 1;
        for (int k = 1; k <= rowIndex; k++)
        {
            val = val * (rowIndex - k + 1) / k;
            ans.push_back((int)val);
        }
        return ans;
    }
};