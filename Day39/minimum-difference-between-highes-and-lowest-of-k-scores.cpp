// LeetCode 1984
// You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
// Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
// Return the minimum possible difference.

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = k - 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - k + 1];
            ans = min(ans, diff);
        }
        return ans;
    }
};