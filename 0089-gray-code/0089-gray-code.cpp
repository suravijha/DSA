class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};

        for (int bits = 0; bits < n; bits++) {
            int add = 1 << bits;

            for (int i = ans.size() - 1; i >= 0; i--) {
                ans.push_back(ans[i] + add);
            }
        }

        return ans;
    }
};