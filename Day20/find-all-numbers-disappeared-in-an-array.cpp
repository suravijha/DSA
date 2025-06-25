// LeetCode 448
// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        vector<bool> count(n, 0);
        for (int num : nums)
        {
            count[num - 1] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (count[i] == 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};