class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree, outdegree;

        for (auto &p : pairs) {
            graph[p[0]].push_back(p[1]);
            outdegree[p[0]]++;
            indegree[p[1]]++;
        }

        int start = pairs[0][0];

        // Find Eulerian path starting vertex
        for (auto &[node, degree] : outdegree) {
            if (degree == indegree[node] + 1) {
                start = node;
                break;
            }
        }

        vector<int> path;
        vector<int> st;

        st.push_back(start);

        while (!st.empty()) {
            int node = st.back();

            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();

                st.push_back(next);
            } else {
                path.push_back(node);
                st.pop_back();
            }
        }

        reverse(path.begin(), path.end());

        vector<vector<int>> ans;

        for (int i = 0; i + 1 < path.size(); i++) {
            ans.push_back({path[i], path[i + 1]});
        }

        return ans;
    }
};