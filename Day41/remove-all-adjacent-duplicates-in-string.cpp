// LeetCode 1047
// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<int> st;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.empty() && s[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};