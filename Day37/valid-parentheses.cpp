// LeetCode 20
/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> check;
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                check.push(ch);
            }
            else
            {
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