// LeetCode 2367
// You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
// i < j < k,
// nums[j] - nums[i] == diff, and
// nums[k] - nums[j] == diff.
// Return the number of unique arithmetic triplets.

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int num : nums)
        {
            hash[num]++;
        }
        for (auto x : hash)
        {
            if (hash.find(x.first + diff) != hash.end())
            {
                if (hash.find(x.first + 2 * diff) != hash.end())
                    ans++;
            }
        }
        return ans;
    }
};