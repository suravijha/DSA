// LeetCode 643
// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            ans += nums[i];
        }
        double current = ans;
        for (int i = k; i < n; i++) {
            current += nums[i] - nums[i - k];
            ans = max(ans, current);
        }
        return ans / k;
    }
};