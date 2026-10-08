class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int balance  = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (balance)
                    ans += s[i];
                
                balance++;
            } else {
                balance--;

                if (balance)
                    ans += s[i];
            }
        }

        return ans;
    }
};