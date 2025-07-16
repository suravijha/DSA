// LeetCode 424
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> count(26, 0);
        int length = 0;
        int left = 0;
        int freq = 0;

        for (int right = 0; right < s.size(); right++)
        {
            count[s[right] - 'A']++;
            freq = max(freq, count[s[right] - 'A']);

            while ((right - left + 1) - freq > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            length = max(length, right - left + 1);
        }

        return length;
    }
};