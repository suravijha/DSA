class Solution {
private:
    vector<string> ans;

    bool valid(string temp) {
        if (temp.size() > 3 || temp.size() == 0) 
            return false;

        if (temp.size() > 1 && temp[0] == '0')
            return false;

        if (temp.size() && stoi(temp) > 255) 
            return false;

        return true;
    }

    void solve(string& s, string curr, int index, int parts) {
        if (parts == 3) {
            if (valid(s.substr(index)))
                ans.push_back(curr + s.substr(index));

            return;
        }

        int sz = s.size();

        for (int i = index; i < min(index + 3, sz); i++) {
            if (valid(s.substr(index, i - index + 1))) {
                curr.push_back(s[i]);
                curr.push_back('.');
                solve(s, curr, i + 1, parts + 1);
                curr.pop_back();
            }
        }

    }

public:
    vector<string> restoreIpAddresses(string s) {
        string curr;
        solve(s, curr, 0, 0);
        
        return ans;
    }
};