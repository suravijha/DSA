// LeetCode 347
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for (int num : nums)
        {
            count[num]++;
        }
        for (const auto &entry : count)
        {
            freq[entry.second].push_back(entry.first);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--)
        {
            for (int n : freq[i])
            {
                res.push_back(n);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};