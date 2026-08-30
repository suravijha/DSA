class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int idx = nums[i] - 1;

            if (nums[i] != nums[idx]) {
                swap(nums[i], nums[idx]);
            } else {
                i++;
            }
        }

        int twice = 0;
        int missing = 0;

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                twice = nums[i];
                missing = i + 1;
            }
        }

        return {twice, missing};
    }
};