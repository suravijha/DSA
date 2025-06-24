// LeetCode 2006
// Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[j] - nums[i]) == k)
                    ans++;
            }
        }
        return ans;
    }
};