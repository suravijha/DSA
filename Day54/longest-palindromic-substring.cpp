// LeetCode 5
// Given a string s, return the longest palindromic substring in s.

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);
            int maxLen = max(odd, even);
            if (maxLen > end - start)
            {
                start = i - (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(string s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};