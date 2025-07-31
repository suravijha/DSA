// LeetCode 1394
// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
// Return the largest lucky integer in the array. If there is no lucky integer return -1.

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> hash;
        for (int num : arr)
        {
            hash[num]++;
        }
        int ans = -1;
        for (auto x : hash)
        {
            if (x.first == x.second)
            {
                ans = max(ans, x.first);
            }
        }
        return ans;
    }
};