// LeetCode 1
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int value = target - nums[i];
            if (hash.find(value) != hash.end())
            {
                ans.push_back(hash[value]);
                ans.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};