// LeetCode 3190
// You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.
// Return the minimum number of operations to make all elements of nums divisible by 3.

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int ans = 0;
        for (int n : nums)
        {
            if (n % 3)
                ans++;
        }
        return ans;
    }
};