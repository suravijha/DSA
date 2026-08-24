class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> visit(n, false);
        vector<int> dist(n, INT_MAX);

        int node = 0;
        int res = 0;
        int edges = 0;

        while (edges < n - 1) {
            visit[node] = true;
            int nextNode = -1;

            for (int i = 0; i < n; i++) {
                if (visit[i]) 
                    continue;

                int curr = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);

                dist[i] = min(dist[i], curr);
                if (nextNode == -1 || dist[nextNode] > dist[i])
                    nextNode = i;
            }

            res += dist[nextNode];
            node = nextNode;

            edges++;
        }

        return res;
    }
};