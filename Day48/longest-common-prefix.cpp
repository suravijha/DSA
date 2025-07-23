// LeetCode 14
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < min(prefix.size(), strs[i].size()))
            {
                if (prefix[j] != strs[i][j])
                    break;
                j++;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};