class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;

        for (int n: nums) {
            if (n == 0)
                curr = 0;
            else
                curr++;
            ans = max(ans, curr);
        }

        return ans;
    }
};