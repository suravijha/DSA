// LeetCode 16
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int current = abs(target - sum);
                if (current < diff)
                {
                    diff = current;
                    ans = sum;
                }
                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else
                    return target;
            }
        }
        return ans;
    }
};