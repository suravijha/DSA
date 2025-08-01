// LeetCode 13
// Given a roman numeral, convert it to an integer.

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]])
            {
                res -= roman[s[i]];
            }
            else
            {
                res += roman[s[i]];
            }
        }

        return res;
    }
};