// LeetCode 485
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                count++;
            else
                count = 0;
            ans = max(count, ans);
        }
        return ans;
    }
};