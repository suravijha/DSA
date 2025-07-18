// LeetCode 2486
// You are given two strings s and t consisting of only lowercase English letters.
// Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int val = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[val])
                val++;
        }

        return m - val;
    }
};