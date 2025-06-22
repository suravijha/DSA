// LeetCode 169
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.You may assume that the majority element always exists in the array.

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int ans;
        unordered_map<int, int> hash;
        for (int num : nums)
        {
            hash[num]++;
        }
        for (auto x : hash)
        {
            if (x.second > n / 2)
                ans = x.first;
        }
        return ans;
    }
};