class TrieNode {
public:
    vector<TrieNode*> children;
    string word;

    TrieNode() {
        children.resize(26, nullptr);
        word = "";
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;

        for (char c: word) {
            if (cur -> children[c - 'a'] == nullptr) {
                cur -> children[c - 'a'] = new TrieNode();
            }

            cur = cur -> children[c - 'a'];
        }

        cur -> word = word;
    }
};

class Solution {
private:
    int m, n;
    vector<string> ans;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];

        TrieNode* next = node -> children[c - 'a'];

        if (next == nullptr) {
            return;
        }

        if (!(next -> word.empty())) {
            ans.push_back(next -> word);

            next -> word = "";
        }

        board[i][j] = '#';

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                board[ni][nj] != '#') {

                dfs(board, ni, nj, next);
            }
        }

        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie();

        for (auto& s: words) {
            t -> insert(s);
        }

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, t -> root);
            }
        }

        return ans;
    }
};