// LeetCode 81
/* There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.*/

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] == nums[start])
            {
                start++;
                continue;
            }
            if (nums[start] <= nums[mid])
            {
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};