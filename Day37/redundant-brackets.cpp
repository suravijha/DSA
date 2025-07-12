// Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. 
// The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
// A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    stack<char> check;
    for (char c : s)
    {
        if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
        {
            check.push(c);
        }
        else if (c == ')') {
            bool ans = true;
            while (check.top() != '(')
            {
                char top = check.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    ans = false;
                check.pop();
            }
            check.pop();
            if (ans)
                return true;
        }
    }
    return false;
}
