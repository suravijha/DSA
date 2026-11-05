class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        arr2.push_back(INT_MAX);

        int ans = 0;

        for (int x: arr1) {
            int p = lower_bound(arr2.begin(), arr2.end(), x - d) - arr2.begin();

            if (arr2[p] > x + d) {
                ans++;
            }
        }

        return ans;
    }
};