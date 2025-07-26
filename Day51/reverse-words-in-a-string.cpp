// LeetCode 151
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans;
        int i = s.size() - 1;
        if (i < 0)
            return ans;

        while (i >= 0 && s[i] == ' ')
            i--;

        while (i >= 0)
        {
            int j = i;

            while (i >= 0 && s[i] != ' ')
                i--;

            ans += s.substr(i + 1, j - i);
            ans += ' ';

            while (i >= 0 && s[i] == ' ')
                i--;
        }

        if (!ans.empty())
            ans.pop_back();

        return ans;
    }
};