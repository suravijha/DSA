// LeetCode 8
/* Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
Return the integer as the final result. */

class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.empty())
            return 0;

        int sign = 1, index = 0;
        long long res = 0;
        int n = s.size();

        while (index < n && s[index] == ' ')
        {
            index++;
        }

        if (index == n)
            return 0;

        if (s[index] == '+')
        {
            index++;
        }
        else if (s[index] == '-')
        {
            sign = -1;
            index++;
        }

        while (index < n && isdigit(s[index]))
        {
            int digit = s[index] - '0';
            res = res * 10 + digit;

            if (sign * res <= INT_MIN)
            {
                return INT_MIN;
            }
            if (sign * res >= INT_MAX)
            {
                return INT_MAX;
            }

            index++;
        }

        return res * sign;
    }
};