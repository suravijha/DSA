class Solution {
private:
    int solve(vector<int>& heights) {
        stack<int> s;

        int maxi = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();

                int width = s.empty() ? i : i - s.top() - 1;
                maxi = max(maxi, height * width);
            }
            s.push(i);
        }

        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int n = matrix[0].size();
        vector<int> heights(n, 0);

        int maxi = 0;

        for (auto& row: matrix) {
            for (int i = 0; i < n; i++) {
                if ((row[i]) == '1')
                    heights[i]++;
                else
                    heights[i] = 0;
            }

            maxi = max(maxi, solve(heights));
        }

        return maxi;
    }
};