// LeetCode 271
// Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans = "";
        for (const string &s : strs)
        {
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            ans.push_back(s.substr(i, length));
            i = j;
        }
        return ans;
    }
};