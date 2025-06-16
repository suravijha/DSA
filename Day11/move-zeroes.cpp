// LeetCode 283
/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        while (j < n) {
            if (nums[j] == 0) {
                j++;
            } else {
                swap(nums[i], nums[j]);
                j++;
                i++;
            }
        }
    }
};