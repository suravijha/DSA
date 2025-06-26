// LeetCode 1295
// Given an array nums of integers, return how many of them contain an even number of digits.

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
        {
            int digits = (int)(log10(num) + 1);
            if ((digits & 1) == 0)
                ans++;
        }
        return ans;
    }
};