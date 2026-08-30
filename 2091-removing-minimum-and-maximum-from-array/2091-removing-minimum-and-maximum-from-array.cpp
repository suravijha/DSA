class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mini])
                mini = i;

            if (nums[i] > nums[maxi])
                maxi = i;
        }

        int front = max(mini, maxi) + 1;
        int back = max(n - maxi, n - mini);
        int both = min(maxi, mini) + 1 + n - max(maxi, mini);

        int ans = min(front, min(back, both));

        return ans;
    }
};