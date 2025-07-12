// Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.

void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int top = stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(top);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
        return;
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}