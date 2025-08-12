// LeetCode 43
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        int k = 0;
        while (k < res.size() && res[k] == 0) {
            k++;
        }

        string out = "";
        for (; k < res.size(); k++) {
            out.push_back('0' + res[k]);
        }
        return out.empty() ? "0" : out;
    }
};