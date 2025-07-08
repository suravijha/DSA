class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int len = original.size();
        vector<vector<int>> ans;
        if (m * n != len)
            return ans;
        int i = 0;
        while (i < len)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                temp[j] = original[i++];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};