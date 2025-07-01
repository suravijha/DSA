// LeetCode 219
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> present;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (present.find(nums[i]) != present.end())
                return true;
            present.insert(nums[i]);
            if (present.size() > k)
                present.erase(nums[i - k]);
        }
        return false;
    }
};