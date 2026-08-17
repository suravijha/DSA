class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        k--;

        string ans = "";

        int fact = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        for (int remaining = n; remaining >= 1; remaining--) {

            int index = k / fact;

            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            k %= fact;

            if (remaining > 1) {
                fact /= (remaining - 1);
            }
        }

        return ans;
    }
};