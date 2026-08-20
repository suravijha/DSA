class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int ans = 1;

        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        float prev = (float)(target - cars[0].first) / cars[0].second;

        for (int i = 1; i < n; i++) {
            float curr = (float)(target - cars[i].first) / cars[i].second;

            if (curr > prev) {
                ans++;
                prev = curr;
            }
        }

        return ans;
    }
};