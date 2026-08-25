class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, int>> q;

        q.push({src, 0});
        dist[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();

            while (size--) {
                auto [u, cost] = q.front();
                q.pop();

                for (auto &[v, price] : adj[u]) {
                    int newCost = cost + price;

                    if (newCost < dist[v]) {
                        dist[v] = newCost;
                        q.push({v, newCost});
                    }
                }
            }

            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};