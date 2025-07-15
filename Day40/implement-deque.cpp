/* Design a data structure to implement deque of size ‘N’. It should support the following operations:
pushFront(X): Inserts an element X in the front of the deque. Returns true if the element is inserted, otherwise false.
pushRear(X): Inserts an element X in the back of the deque. Returns true if the element is inserted, otherwise false.
popFront(): Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
popRear(): Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
getFront(): Returns the first element of the deque. If the deque is empty, it returns -1.
getRear(): Returns the last element of the deque. If the deque is empty, it returns -1.
isEmpty(): Returns true if the deque is empty, otherwise false.
isFull(): Returns true if the deque is full, otherwise false.*/

#include <bits/stdc++.h>
class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty())
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = arr[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front)
            return true;
        else
            return false;
    }
};