// You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

#include <bits/stdc++.h>

void solve(stack<int> &myStack, int insert)
{
    if (myStack.empty())
    {
        myStack.push(insert);
        return;
    }
    int top = myStack.top();
    myStack.pop();
    solve(myStack, insert);
    myStack.push(top);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}
