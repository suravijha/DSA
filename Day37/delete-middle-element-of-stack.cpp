// You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.

#include <bits/stdc++.h>

void solve(stack<int> &inputStack, int count, int N)
{
    if (count == N / 2)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, N);
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}