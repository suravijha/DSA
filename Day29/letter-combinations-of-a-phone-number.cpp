// LeetCode 17
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

class Solution
{
private:
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
    {
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }
        string value = mapping[digits[index] - '0'];
        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};