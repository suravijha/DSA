class Solution {
private:
    void backtrack(unordered_map<int, int>& counter, vector<int>& comb, int n, vector<vector<int>>& results) {
        if (comb.size() == n) {
            results.push_back(comb);
            return;
        }

        for (auto& item: counter) {
            int num = item.first;
            int count = item.second;

            if (count == 0)
                continue;
            
            comb.push_back(num);
            counter[num]--;

            backtrack(counter, comb, n, results);

            comb.pop_back();
            counter[num]++;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;

        unordered_map<int, int> counter;

        for (int n: nums) {
            counter[n]++;
        }

        vector<int> comb;
        backtrack(counter, comb, nums.size(), results);

        return results;
    }
};