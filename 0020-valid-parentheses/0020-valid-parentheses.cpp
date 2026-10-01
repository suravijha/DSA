class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for (char ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                check.push(ch);
            } else {
                if (check.empty())
                    return false;
                char top = check.top();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{'))
                    check.pop();
                else
                    return false;
            }
        }
        return (check.empty());
    }
};