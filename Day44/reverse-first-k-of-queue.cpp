// Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.
// If the size of queue is smaller than the given k , then return the original queue.

class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        int n = q.size();
        if (n < k)
            return q;

        stack<int> s;

        for (int i = 0; i < k; i++)
        {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        for (int i = 0; i < k; i++)
        {
            int element = s.top();
            s.pop();
            q.push(element);
        }

        for (int i = 0; i < n - k; i++)
        {
            int element = q.front();
            q.pop();
            q.push(element);
        }

        return q;
    }
};