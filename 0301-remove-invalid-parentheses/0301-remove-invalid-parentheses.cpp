class Solution {
private:
    unordered_set<string> ans;

    void solve(string& s, string& curr, int index, int open, int close, int remo, int remc) {
        if (index == s.size()) {
            if (remo == 0 && remc == 0)
                ans.insert(curr);

            return;
        }

        if (s[index] == '(') {
            if (remo > 0)
                solve(s, curr, index + 1, open, close, remo - 1, remc);

            curr.push_back('(');
            solve(s, curr, index + 1, open + 1, close, remo, remc);
            curr.pop_back();

        } else if (s[index] == ')') {
            if (remc > 0)
                solve(s, curr, index + 1, open, close, remo, remc - 1);

            if (close < open) {
                curr.push_back(')');
                solve(s, curr, index + 1, open, close + 1, remo, remc);
                curr.pop_back();
            }

        } else {
            curr.push_back(s[index]);
            solve(s, curr, index + 1, open, close, remo, remc);
            curr.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int remo = 0;
        int remc = 0;

        for (char c: s) {
            if (c == '(') {
                remo++;
            } else if (c == ')') {
                if (remo > 0) remo--;
                else remc++;
            }
        }

        string curr;
        solve(s, curr, 0, 0, 0, remo, remc);

        return vector<string>(ans.begin(), ans.end());
    }
};