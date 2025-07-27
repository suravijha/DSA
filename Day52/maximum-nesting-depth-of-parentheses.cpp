// LeetCode 1614
// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        int current = 0;
        for (char c : s)
        {
            if (c == '(')
                current++;
            else if (c == ')')
                current--;
            ans = max(current, ans);
        }
        return ans;
    }
};