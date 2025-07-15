/* Implement a Queue Data Structure specifically to store integer data using a Singly Linked List or an array.
You need to implement the following public functions :
1. Constructor: It initializes the data members as required.
2. enqueue(data): This function should take one argument of type integer. It enqueues the element into the queue.
3. dequeue(): It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.
4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.
5. isEmpty(): It returns a boolean value indicating whether the queue is empty or not.*/

#include <bits/stdc++.h> 
class Queue {
    int* arr;
    int frontIndex;
    int rear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size = 10000;
        arr = new int[size];
        frontIndex = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if (frontIndex == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (rear != size) {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (frontIndex == rear) {
            return -1;
        } else {
            int element = arr[frontIndex];
            frontIndex++;
            return element;
        }
    }

    int front() {
        if (frontIndex == rear) {
            return -1;
        } else {
            return arr[frontIndex];
        }
    }
};