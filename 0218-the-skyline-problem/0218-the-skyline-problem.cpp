class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;

        multiset<int> pq;
        pq.insert(0);

        vector<pair<int, int>> points;

        for (auto& b: buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }

        sort(points.begin(), points.end());

        int height = 0;

        for (int i = 0; i < points.size(); i++) {
            int p = points[i].first;
            int h = points[i].second;

            if (h < 0) {
                pq.insert(-h);
            } else {
                pq.erase(pq.find(h));
            }

            auto t = *pq.rbegin();
            if (height != t) {
                height = t;
                ans.push_back({p, t});
            }
        }

        return ans;
    }
};