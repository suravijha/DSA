class Solution {
private:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int left, int right) {
        if (left > right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = 0;

        for (int i = left; i <= right; i++) {
            int mul = nums[left - 1] * nums[i] * nums[right + 1];
            int coins = solve(nums, left, i - 1) + mul + solve(nums, i + 1, right);
            
            ans = max(ans, coins);
        }

        return dp[left][right] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return solve(nums, 1, n - 2);
    }
};