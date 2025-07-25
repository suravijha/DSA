// LeetCode 30
// You are given a string s and an array of strings words. All the strings of words are of the same length.
// A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
// Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return ans;

        unordered_map<string, int> wordsMap;
        for (const string &word : words)
        {
            wordsMap[word]++;
        }

        for (int i = 0; i < wordLen; i++)
        {
            int left = i, right = i;
            unordered_map<string, int> window;
            int count = 0;

            while (right + wordLen <= s.size())
            {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordsMap.count(word))
                {
                    window[word]++;
                    count++;

                    while (window[word] > wordsMap[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount)
                    {
                        ans.push_back(left);
                    }
                }
                else
                {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};