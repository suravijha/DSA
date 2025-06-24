// LeetCode 2824
// Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int start = 0;
        int end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] + nums[end] < target)
            {
                ans += end - start;
                start++;
            }
            else
            {
                end--;
            }
        }
        return ans;
    }
};