// LeetCode 58
// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        int index = s.size() - 1;
        while (s[index] == ' ')
            index--;
        while (index >= 0)
        {
            if (s[index] == ' ')
                break;
            else
                ans++;
            index--;
        }
        return ans;
    }
};