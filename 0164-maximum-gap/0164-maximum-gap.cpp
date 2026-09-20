class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        if (mini == maxi)
            return 0;

        vector<int> bucketLarge(n, INT_MIN);
        vector<int> bucketSmall(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            int index = (nums[i] - mini) * (n - 1) / (maxi - mini);
            bucketLarge[index] = max(bucketLarge[index], nums[i]);
            bucketSmall[index] = min(bucketSmall[index], nums[i]);
        }

        int ans = 0;
        int i = 0, j = 1;

        while (j < n) {
            if (bucketLarge[j] == INT_MIN) {
                j++;
            } else if (bucketLarge[i] == INT_MIN) {
                i++;
            } else {
                ans = max(ans, bucketSmall[j] - bucketLarge[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};