// Leetcode 1752
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array.

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0; 
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) count++;
        }
        if (nums[0] < nums[n - 1]) count++;
        return count <= 1;
    }
};