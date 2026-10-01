class Solution {
private:
    vector<vector<int>> ans;

    void solve(vector<int>& current, int n, int k, int index) {
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i <= n; i++) {
            current.push_back(i);
            solve(current, n, k, i + 1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        solve(current, n, k, 1);
        return ans;
    }
};