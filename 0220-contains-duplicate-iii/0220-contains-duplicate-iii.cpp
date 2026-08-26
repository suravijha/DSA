class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0)
            return false;

        set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            if (i > indexDiff)
                window.erase(nums[i - indexDiff - 1]);

            int low = nums[i] - valueDiff;
            int high = nums[i] + valueDiff;

            auto it = window.lower_bound(low);

            if (it != window.end() && *it <= high)
                return true;

            window.insert(nums[i]);
        }

        return false;
    }
};