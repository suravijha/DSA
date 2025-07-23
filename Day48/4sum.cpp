// LeetCode 18
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n, a, b, c, and d are distinct, and
// nums[a] + nums[b] + nums[c] + nums[d] == target

class Solution
{
    vector<vector<int>> res;
    vector<int> quad;

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        kSum(nums, 4, 0, (long long)target);
        return res;
    }

private:
    void kSum(vector<int> &nums, int k, int start, long long target)
    {
        if (k == 2)
        {
            int l = start, r = nums.size() - 1;
            while (l < r)
            {
                long long sum = (long long)nums[l] + nums[r];
                if (sum < target)
                {
                    l++;
                }
                else if (sum > target)
                {
                    r--;
                }
                else
                {
                    quad.push_back(nums[l]);
                    quad.push_back(nums[r]);
                    res.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
            return;
        }

        for (int i = start; i < nums.size() - k + 1; i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            quad.push_back(nums[i]);
            kSum(nums, k - 1, i + 1, target - nums[i]);
            quad.pop_back();
        }
    }
};