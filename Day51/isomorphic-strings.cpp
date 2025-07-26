// LeetCode 205
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> charMap;

        for (int i = 0; i < s.size(); i++)
        {
            char sc = s[i];
            char tc = t[i];

            if (charMap.count(sc))
            {
                if (charMap[sc] != tc)
                    return false;
            }
            else
            {
                for (auto &pair : charMap)
                {
                    if (pair.second == tc)
                        return false;
                }
                charMap[sc] = tc;
            }
        }

        return true;
    }
};