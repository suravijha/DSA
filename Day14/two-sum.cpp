// LeetCode 1
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash; 

        for (int i = 0; i < n; i++) {
            int value = target - nums[i];
            if (hash.find(value) != hash.end()) {
                return {hash[value], i};
            }
            hash.insert({nums[i], i});
        }
        return {};
    }
};