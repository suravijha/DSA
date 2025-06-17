// LeetCode 3550
// You are given an integer array nums.
// Return the smallest index i such that the sum of the digits of nums[i] is equal to i.
// If no such index exists, return -1.

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            if (sum == i) return i;
        }
        return -1;
    }
};