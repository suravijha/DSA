// LeetCode 977
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int start = 0;
        int end = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(nums[start]) > abs(nums[end]))
            {
                ans[i] = nums[start] * nums[start];
                start++;
            }
            else
            {
                ans[i] = nums[end] * nums[end];
                end--;
            }
        }
        return ans;
    }
};