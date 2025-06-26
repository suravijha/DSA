// LeetCode 1869
// Given a binary string s, return true if the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's in s, or return false otherwise.
// Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.

class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int one = 0;
        int zero = 0;
        int temp1 = 0, temp0 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                temp1++;
                temp0 = 0;
            }
            else
            {
                temp0++;
                temp1 = 0;
            }
            one = max(one, temp1);
            zero = max(zero, temp0);
        }
        return one > zero;
    }
};