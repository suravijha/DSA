// LeetCode 2465
/* You are given a 0-indexed integer array nums of even length. As long as nums is not empty, you must repetitively:
1. Find the minimum number in nums and remove it.
2. Find the maximum number in nums and remove it.
3. Calculate the average of the two removed numbers.
Return the number of distinct averages calculated using the above process.
Note that when there is a tie for a minimum or maximum number, any can be removed. */

class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        unordered_set<int> averages;
        while (left < right)
        {
            int average = nums[left] + nums[right];
            averages.insert(average);
            left++;
            right--;
        }
        return averages.size();
    }
};