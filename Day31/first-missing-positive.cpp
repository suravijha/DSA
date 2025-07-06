// LeetCode 41
// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 1;
        for (int num : nums)
        {
            if (ans == num)
                ans++;
        }
        return ans;
    }
};