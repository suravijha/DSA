// Design a stack that supports getMin() in O(1) time and O(1) extra space.
// Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.

#include <stack>
class SpecialStack
{
public:
    stack<int> s;
    int mini;
    void push(int data)
    {
        // Implement the push() function.
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    void pop()
    {
        // Implement the pop() function.
        if (s.empty())
            return;
        int curr = s.top();
        s.pop();
        if (!(curr > mini))
        {
            mini = 2 * mini - curr;
        }
    }

    int top()
    {
        // Implement the top() function.
        if (s.empty())
            return -1;
        int curr = s.top();
        if (curr < mini)
            return mini;
        else
            return curr;
    }

    int getMin()
    {
        if (s.empty())
            return -1;
        return mini;
    }
};