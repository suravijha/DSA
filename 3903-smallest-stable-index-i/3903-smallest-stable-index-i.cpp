class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> mini = nums;

        for (int i = nums.size() - 2; i >= 0; i--)
            mini[i] = min(mini[i], mini[i + 1]);

        int maxi = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);

            int ins = maxi - mini[i];
            if (ins <= k)
                return i;
        }

        return -1;
    }
};