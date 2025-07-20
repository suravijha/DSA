// LeetCode 6
/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows. */

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string ans;
        int n = s.size();

        for (int r = 0; r < numRows; r++)
        {
            int increment = 2 * (numRows - 1);
            for (int i = r; i < n; i += increment)
            {
                ans += s[i];
                if (r > 0 && r < numRows - 1 && i + increment - 2 * r < n)
                {
                    ans += s[i + increment - 2 * r];
                }
            }
        }

        return ans;
    }
};