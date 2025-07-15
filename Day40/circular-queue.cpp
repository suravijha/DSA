/* You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:
1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.
2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.*/

#include <bits/stdc++.h>
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = value;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};