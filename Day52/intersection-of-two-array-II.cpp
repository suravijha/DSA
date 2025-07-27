// LeetCode 350
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int num : nums1)
        {
            hash[num]++;
        }
        for (int num : nums2)
        {
            if (hash.find(num) != hash.end() && hash[num])
            {
                ans.push_back(num);
                hash[num]--;
            }
        }
        return ans;
    }
};