// You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked list such that every element in the linked list occurs only once.

#include <bits/stdc++.h>
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    unordered_set<int> visited;
    Node *curr = head;
    visited.insert(curr->data);
    while (curr != NULL && curr->next != NULL)
    {
        if (visited.count(curr->next->data))
        {
            curr->next = curr->next->next;
        }
        else
        {
            visited.insert(curr->next->data);
            curr = curr->next;
        }
    }
    return head;
}