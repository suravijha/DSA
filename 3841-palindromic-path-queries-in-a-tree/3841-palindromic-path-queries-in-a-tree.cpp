class Solution {
private:
    int n, LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, initialP;
    vector<int> bit;
    int timer = 0;

    int mask(char c) {
        return 1 << (c - 'a');
    }

    void add(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int queryBIT(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void dfs(int u, int p, string& s) {
        tin[u] = ++timer;
        up[u][0] = p;
        initialP[u] = mask(s[u]);

        if (u != p) {
            initialP[u] ^= initialP[p];
            depth[u] = depth[p] + 1;
        }

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v != p)
                dfs(v, u, s);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        initialP.resize(n);
        up.assign(n, vector<int>(LOG));
        bit.assign(n + 1, 0);

        dfs(0, 0, s);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);

                if (delta != 0) {
                    add(tin[u], delta);
                    add(tout[u] + 1, delta);

                    s[u] = c;
                }
            } 
            else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int pu = initialP[u] ^ queryBIT(tin[u]);
                int pv = initialP[v] ^ queryBIT(tin[v]);

                int pathMask = pu ^ pv ^ mask(s[w]);

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};