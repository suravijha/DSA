// LeetCode 2016
// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
// Return the maximum difference. If no such i and j exists, return -1.

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int minValue = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > minValue)
                ans = max(ans, nums[i] - minValue);
            else 
                minValue = nums[i];
        }
        return ans;
    }
};