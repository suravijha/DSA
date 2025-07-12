/* Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced.
Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.
Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.
Return -1 if it is impossible to make ‘STR’ valid.*/

#include <bits/stdc++.h>
int findMinimumCost(string str)
{

    if (str.length() % 2 == 1)
        return -1;

    stack<char> s;

    for (char c : str)
    {
        if (c == '{')
        {
            s.push(c);
        }
        else
        {
            if (!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(c);
        }
    }

    int open = 0;
    int close = 0;

    while (!s.empty())
    {
        if (s.top() == '{')
            open++;
        else
            close++;
        s.pop();
    }

    int ans = (open + 1) / 2 + (close + 1) / 2;

    return ans;
}