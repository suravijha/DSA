class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int len = 0;

        unordered_map<int, int> freq;

        while (right < nums.size()) {
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }
};