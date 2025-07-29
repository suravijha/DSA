// LeetCode 38
/* The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run).
Given a positive integer n, return the nth element of the count-and-say sequence.*/

class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        solve(1, n, ans);
        return ans;
    }

private:
    void solve(int index, int n, string &ans)
    {
        if (index >= n)
            return;
        string prev = ans;
        ans = "";
        int left = 0, count = 0;
        for (int right = 0; right < prev.size(); right++)
        {
            if (prev[left] == prev[right])
            {
                count++;
            }
            else
            {
                ans += to_string(count) + prev[left];
                left = right;
                count = 1;
            }
        }
        ans += to_string(count) + prev[left];
        return solve(index + 1, n, ans);
    }
};