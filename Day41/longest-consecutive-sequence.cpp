// LeetCode 128
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int ans = 0;

        for (int num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int length = 1;
                while (numSet.find(num + length) != numSet.end())
                {
                    length++;
                }
                ans = max(ans, length);
            }
        }

        return ans;
    }
};