// LeetCode 2124
// Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

class Solution
{
public:
    bool checkString(string s)
    {
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == 'b' && s[i + 1] == 'a')
                return false;
        }
        return true;
    }
};