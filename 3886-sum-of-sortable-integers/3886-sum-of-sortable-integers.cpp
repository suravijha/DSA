class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        sort(target.begin(), target.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n && valid; start += k) {
                vector<int> a(nums.begin() + start, nums.begin() + start + k);
                vector<int> b(target.begin() + start, target.begin() + start + k);

                sort(a.begin(), a.end());

                if (a != b) {
                    valid = false;
                    break;
                }

                int descents = 0;
                for (int i = start; i < start + k; i++) {
                    int next = (i + 1 == start + k) ? start : i + 1;
                    if (nums[i] > nums[next]) descents++;
                }

                if (descents > 1) valid = false;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};