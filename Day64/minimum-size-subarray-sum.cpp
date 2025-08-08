// LeetCode 209
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. 
// If there is no such subarray, return 0 instead.

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        int left = 0;
        int curr = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            curr += nums[right];
            while (curr >= target)
            {
                if (right - left + 1 < ans)
                {
                    ans = right - left + 1;
                }
                curr -= nums[left];
                left++;
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};