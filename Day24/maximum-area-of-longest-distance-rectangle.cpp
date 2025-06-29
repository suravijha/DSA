// LeetCode 3000
// You are given a 2D 0-indexed integer array dimensions.
// For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.
// Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int ans = 0;
        float maxdia = 0;
        int n = dimensions.size();
        for (int i = 0; i < n; i++)
        {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            float dia = sqrt(l * l + b * b);
            if (dia > maxdia)
            {
                maxdia = dia;
                ans = l * b;
            }
            else if (dia == maxdia)
            {
                ans = max(ans, l * b);
            }
        }
        return ans;
    }
};