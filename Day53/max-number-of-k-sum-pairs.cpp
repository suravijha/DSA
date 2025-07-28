// LeetCode 1679
// You are given an integer array nums and an integer k.
// In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
// Return the maximum number of operations you can perform on the array.

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                ans++;
                i++;
                j--;
            }
            else if (nums[i] + nums[j] < k)
                i++;
            else
                j--;
        }
        return ans;
    }
};