// LeetCode 1446
// The power of the string is the maximum length of a non-empty substring that contains only one unique character.
// Given a string s, return the power of s.

class Solution
{
public:
    int maxPower(string s)
    {
        int ans = 1;
        int count = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;
            ans = max(count, ans);
        }
        return ans;
    }
};