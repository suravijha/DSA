// LeetCode 75
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int current = 0;
        while (current <= end)
        {
            if (nums[current] == 0)
            {
                swap(nums[current], nums[start]);
                current++;
                start++;
            }
            else if (nums[current] == 1)
            {
                current++;
            }
            else
            {
                swap(nums[current], nums[end]);
                end--;
            }
        }
    }
};