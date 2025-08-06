// LeetCode 2365
// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
// Return the total number of bad pairs in nums.

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        long long good = 0, total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int key = nums[i] - i;
            good += hash[key];
            hash[key]++;
            total += i;
        }
        return total - good;
    }
};