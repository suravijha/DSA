// LeetCode 1832
// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<bool> present(26, 0);
        for (char c : sentence)
        {
            present[c - 'a'] = 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (present[i] == 0)
                return false;
        }
        return true;
    }
};