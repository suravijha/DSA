// LeetCode 90
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution
{
private:
    void solve(vector<int> &nums, vector<int> &output, int index, vector<vector<int>> &ans)
    {
        ans.push_back(output);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            output.push_back(nums[i]);
            solve(nums, output, i + 1, ans);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums, output, 0, ans);
        return ans;
    }
};