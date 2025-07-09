// LeetCode 56
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1])
            {
                prev[1] = max(prev[1], interval[1]);
            }
            else
            {
                ans.push_back(prev);
                prev = interval;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};