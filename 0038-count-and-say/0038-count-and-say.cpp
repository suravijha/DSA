class Solution {
private:
    string solve(string& s) {
        vector<pair<char, int>> freq;

        for (char c: s) {
            if (!freq.empty() && c == freq.back().first) {
                freq.back().second++;
            } else {
                freq.push_back({c, 1});
            }
        }

        string ans = "";

        for (auto& p: freq) {
            ans += to_string(p.second);
            ans += p.first;
        }

        return ans;
    }
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 1; i < n; i++) {
            ans = solve(ans);
        }

        return ans;
    }
};