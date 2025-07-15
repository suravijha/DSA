// LeetCode 974
// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;

        for (int num : nums)
        {
            sum += num;
            int mod = sum % k;
            if (mod < 0)
                mod += k;
            if (prefix.find(mod) != prefix.end())
            {
                count += prefix[mod];
                prefix[mod] += 1;
            }
            else
            {
                prefix[mod] = 1;
            }
        }

        return count;
    }
};