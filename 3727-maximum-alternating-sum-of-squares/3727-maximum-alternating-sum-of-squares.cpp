class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }

        sort(nums.begin(), nums.end());
        long long ans = 0;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            ans += nums[right];

            if (left != right)
                ans -= nums[left];

            left++;
            right--;
        }

        return ans;
    }
};