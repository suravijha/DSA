// LeetCode 167
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
// Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            int sum = numbers[start] + numbers[end];
            if (sum == target)
                break;
            else if (sum < target)
                start++;
            else
                end--;
        }
        return {start + 1, end + 1};
    }
};