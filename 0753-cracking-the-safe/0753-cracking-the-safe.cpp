class Solution {
private:
    unordered_set<string> seen;
    string ans = "";

    void dfs(string node, int k) {
        for (int x = 0; x < k; x++) {
            char c = x + '0';
            string nei = node + c;

            if (seen.find(nei) == seen.end()) {
                seen.insert(nei);

                dfs(nei.substr(1), k);
                ans += c;
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1)
            return "0";

        string b = "";
        for (int i = 0; i < n - 1; i++) {
            b.append("0");
        }

        string start = b;

        dfs(start, k);
        ans.append(start);

        return ans;
    }
};