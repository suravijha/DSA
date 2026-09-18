class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
};

class Solution {
public:

    int kruskal(int n, vector<vector<int>>& edges, int exclude, int force) {
        DSU dsu(n);
        int totalWeight = 0;
        int edgesUsed = 0;

        if (force != -1) {
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];

            dsu.unite(u, v);
            totalWeight += w;
            edgesUsed++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == exclude || i == force)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                totalWeight += w;
                edgesUsed++;
            }
        }

        if (edgesUsed != n - 1)
            return INT_MAX;

        return totalWeight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        int originalWeight = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < edges.size(); i++) {
            int without = kruskal(n, edges, i, -1);

            if (without > originalWeight) {
                critical.push_back(edges[i][3]);
            } else {
                int with = kruskal(n, edges, -1, i);

                if (with == originalWeight)
                    pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};