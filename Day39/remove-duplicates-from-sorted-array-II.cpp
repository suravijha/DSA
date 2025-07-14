// LeetCode 80
// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
// Return k after placing the final result in the first k slots of nums.
// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int k = 2;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] != nums[k - 2])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};