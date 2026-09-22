class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int len = nums[0].size();

        vector<int> ans;

        for (auto &q : queries) {
            int k = q[0];
            int trim = q[1];

            vector<pair<string, int>> v;

            for (int i = 0; i < n; i++) {
                string trimmed = nums[i].substr(len - trim);
                v.push_back({trimmed, i});
            }

            sort(v.begin(), v.end());

            ans.push_back(v[k - 1].second);
        }

        return ans;
    }
};