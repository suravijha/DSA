// You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

#include <bits/stdc++.h>

void sortedInsert(stack<int> &stack, int num)
{
    if (stack.empty() || stack.top() < num)
    {
        stack.push(num);
        return;
    }
    int top = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(top);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack, num);
}