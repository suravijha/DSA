// LeetCode 645
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
// You are given an integer array nums representing the data status of this set after the error.
// Find the number that occurs twice and the number that is missing and return them in the form of an array.

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> present(n + 1, 0);
        vector<int> ans(2);
        for (int num : nums)
        {
            if (present[num])
            {
                ans[0] = num;
            }
            present[num] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            if (present[i] == 0)
            {
                ans[1] = i;
            }
        }
        return ans;
    }
};