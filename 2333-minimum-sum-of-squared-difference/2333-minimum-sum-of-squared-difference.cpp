class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        long long total = 0;

        for (int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            total += nums1[i];
        }

        if (total <= k)
            return 0;

        sort(nums1.begin(), nums1.end(), greater<int>());
        nums1.push_back(0);

        for (int i = 1; i <= n; i++) {
            long long cost = 1LL * (nums1[i - 1] - nums1[i]) * i;

            if (cost <= k) {
                k -= cost;
            } else {
                long long reduction = k / i;
                long long remainder = k % i;
                long long level = nums1[i - 1] - reduction;
                long long ans = (i - remainder) * level * level
                              + remainder * (level - 1) * (level - 1);

                for (int j = i; j < n; j++)
                    ans += 1LL * nums1[j] * nums1[j];

                return ans;
            }
        }

        return 0;
    }
};