// LeetCode 49
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> res;
        for (const auto &s : strs)
        {
            vector<int> count(26, 0);
            for (char c : s)
            {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++)
            {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (const auto &pair : res)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};