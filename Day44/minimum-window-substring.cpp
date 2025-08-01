// LeetCode 76
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> charCount;
        for (char c : t)
        {
            charCount[c]++;
        }

        int targetCharsRemaining = t.length();
        int minWindow[2] = {0, INT_MAX};
        int startIndex = 0;

        for (int endIndex = 0; endIndex < s.length(); endIndex++)
        {
            char ch = s[endIndex];
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0)
            {
                targetCharsRemaining--;
            }
            charCount[ch]--;

            if (targetCharsRemaining == 0)
            {
                while (true)
                {
                    char charAtStart = s[startIndex];
                    if (charCount.find(charAtStart) != charCount.end() && charCount[charAtStart] == 0)
                    {
                        break;
                    }
                    charCount[charAtStart]++;
                    startIndex++;
                }

                if (endIndex - startIndex < (minWindow[1] - minWindow[0]))
                {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                charCount[s[startIndex]]++;
                targetCharsRemaining++;
                startIndex++;
            }
        }
        return minWindow[1] >= s.length() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};