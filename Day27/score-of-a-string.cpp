// LeetCode 3110
// You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
// Return the score of s.

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ans = 0;
        int n = s.length();
        for (int i = 1; i < n; i++)
        {
            ans += abs(s[i] - s[i - 1]);
        }
        return ans;
    }
};