// LeetCode 287
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int num : nums)
        {
            int index = abs(num);
            if (nums[index] < 0)
                return index;
            nums[index] *= -1;
        }
        return -1;
    }
};