// LeetCode 2441
// Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
// Return the positive integer k.If there is no such integer, return -1.

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while (start < end)
        {
            if ((-nums[start]) == nums[end])
            {
                ans = nums[end];
                break;
            }
            else if ((-nums[start]) < nums[end])
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return ans;
    }
};