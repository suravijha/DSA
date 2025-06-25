// LeetCode 2351
// Given a string s consisting of lowercase English letters, return the first letter to appear twice.

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        vector<bool> letters(26, 0);
        char ans;
        for (char c : s)
        {
            int index = c - 'a';
            if (letters[index])
            {
                ans = c;
                break;
            }
            letters[index] = 1;
        }
        return ans;
    }
};