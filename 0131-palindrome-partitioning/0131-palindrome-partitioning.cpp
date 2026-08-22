class Solution {
private:
    vector<vector<string>> ans;

    void solve(string& s, int start, vector<string>& curr) {
        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));

                solve(s, end + 1, curr);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s, 0, curr);

        return ans;
    }
};