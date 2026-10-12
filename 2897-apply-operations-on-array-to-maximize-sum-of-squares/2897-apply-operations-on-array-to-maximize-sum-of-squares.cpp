class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(30, 0);

        for (int n : nums) {
            for (int i = 0; i < 30; i++) {
                cnt[i] += (n >> i) & 1;
            }
        }

        long long res = 0;

        while (k--) {
            long long cur = 0;

            for (int i = 0; i < 30; i++) {
                if (cnt[i] > 0) {
                    cur |= (1LL << i);
                    cnt[i]--;
                }
            }

            res = (res + cur * cur) % MOD;
        }

        return res;
    }
};