// LeetCode 1004
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                k--;
            }
            if (k < 0)
            {
                if (nums[left] == 0)
                {
                    k++;
                }
                left++;
            }
        }

        return nums.size() - left;
    }
};