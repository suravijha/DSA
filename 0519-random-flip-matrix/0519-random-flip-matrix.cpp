class Solution {
private:
    int m, n, remaining;
    unordered_map<int, int> mp;

public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        remaining = m * n;
    }

    vector<int> flip() {
        int r = rand() % remaining;

        int x = mp.count(r) ? mp[r] : r;

        remaining--;

        if (mp.count(remaining))
            mp[r] = mp[remaining];
        else
            mp[r] = remaining;

        return {x / n, x % n};
    }

    void reset() {
        mp.clear();
        remaining = m * n;
    }
};