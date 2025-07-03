// LeetCode 392
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        int n1 = s.size(), n2 = t.size();
        int count = 0;
        while (i < n1 && j < n2)
        {
            if (s[i] == t[j])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count == n1;
    }
};