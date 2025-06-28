// LeetCode 1684
// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
// Return the number of consistent strings in the array words.

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int ans = 0;
        bool allow[26] = {0};
        for (char c : allowed)
        {
            allow[c - 'a'] = true;
        }
        for (string &word : words)
        {
            bool consistent = true;
            for (char c : word)
            {
                if (!allow[c - 'a'])
                {
                    consistent = false;
                    break;
                }
            }
            if (consistent)
                ans++;
        }
        return ans;
    }
};