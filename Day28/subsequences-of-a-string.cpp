// You are given a string 'STR' containing lowercase English letters from a to z inclusive. Your task is to find all non-empty possible subsequences of 'STR'.

#include <bits/stdc++.h>
void solve(string str, string output, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }
    solve(str, output, index + 1, ans);
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    solve(str, output, 0, ans);
    return ans;
}
