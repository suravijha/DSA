class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<pair<int, int>> temp;

        for (int i = 0; i < q; i++) {
            temp.push_back({queries[i], i});
        }

        sort(temp.begin(), temp.end());

        int left = 0;
        int right = 0;
        int active = 0;

        vector<int> cnt(n + 1);
        vector<int> ans(q);

        for (auto [t, i]: temp) {
            while (right < logs.size() && logs[right][1] <= t) {
                if (cnt[logs[right][0]] == 0)
                    active++;
                cnt[logs[right][0]]++;
                right++;
            }

            while (left < right && logs[left][1] < t - x) {
                cnt[logs[left][0]]--;
                if (cnt[logs[left][0]] == 0)
                    active--;
                left++;
            }

            ans[i] = n - active;
        }

        return ans;
    }
};