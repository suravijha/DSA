// LeetCode 1512
// Given an array of integers nums, return the number of good pairs.
// A pair (i, j) is called good if nums[i] == nums[j] and i < j.

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int ans = 0;
        for (int num : nums)
        {
            ans += hash[num];
            hash[num]++;
        }
        return ans;
    }
};