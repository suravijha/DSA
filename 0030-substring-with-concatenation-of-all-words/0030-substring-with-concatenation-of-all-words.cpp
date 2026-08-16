class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int len = words[0].size();
        int n = words.size();

        int totalLen = len * n;

        if (totalLen > s.size()) {
            return ans;
        }

        unordered_map<string, int> need;

        for (string& word : words) {
            need[word]++;
        }

        for (int offset = 0; offset < len; offset++) {
            int left = offset;
            int right = offset;

            int count = 0;

            unordered_map<string, int> have;

            while (right + len <= s.size()) {

                string word = s.substr(right, len);
                right += len;

                if (need.find(word) == need.end()) {
                    have.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                have[word]++;
                count++;

                while (have[word] > need[word]) {
                    string leftWord = s.substr(left, len);

                    have[leftWord]--;
                    left += len;
                    count--;
                }

                if (count == n) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, len);
                    have[leftWord]--;
                    left += len;
                    count--;
                }
            }
        }

        return ans;
    }
};