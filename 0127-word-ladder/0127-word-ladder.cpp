class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() || 
            beginWord == endWord) {
            return 0;
        }

        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        dict.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;

            q.pop();

            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) {
                        continue;
                    }

                    word[i] = c;

                    if (dict.count(word)) {
                        dict.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};