// LeetCode 3467
// You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:
// 1. Replace each even number with 0.
// 2. Replace each odd numbers with 1.
// 3. Sort the modified array in non-decreasing order.
// Return the resulting array after performing these operations.

class Solution
{
public:
    vector<int> transformArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] %= 2;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};