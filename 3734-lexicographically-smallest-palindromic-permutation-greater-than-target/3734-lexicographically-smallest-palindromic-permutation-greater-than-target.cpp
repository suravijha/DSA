class Solution {
private:
    string check(int n, vector<int> freq, string cur, char& center, string& target) {
        for (int i = 25; i >= 0; i--) {
            while (freq[i]) {
                cur += (char)('a' + i);
                freq[i]--;
            }
        }

        string temp = cur;

        if (center != 0) {
            cur += center;
        }

        reverse(temp.begin(), temp.end());
        cur.append(temp.begin(), temp.end());

        return cur > target ? cur : "";
    }
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        if (n == 1) {
            if (s > target)
                return s;
            else
                return "";
        }

        vector<int> freq(26, 0);
        for (char c: s)
            freq[c - 'a']++;

        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                if (center != 0)
                    return "";
                center = 'a' + i;
                freq[i]--;
            }

            freq[i] /= 2;
        }

        int half = n / 2;
        string res = "";
        string prefix = "";

        for (int i = 0; i < half; i++) {
            string cur = prefix;
            bool sol = false;

            for (int j = 0; j < 26; j++) {
                if (freq[j]) {
                    freq[j]--;
                    cur += (char)('a' + j);

                    string poss = check(half, freq, cur, center, target);

                    if (poss != "") {
                        prefix = cur;
                        sol = true;

                        if (res == "")
                            res = poss;
                        else
                            res = min(res, poss);
                        break;
                    }

                    freq[j]++;
                    cur.pop_back();
                }
            }

            if (!sol)
                return "";
        }

        return res;
    }
};