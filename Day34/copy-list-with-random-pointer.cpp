// LeetCode 138
/* A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.
None of the pointers in the new list should point to nodes in the original list.Return the head of the copied linked list.*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }

public:
    Node *copyRandomList(Node *head)
    {
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;
        while (temp)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        unordered_map<Node *, Node *> mapping;
        Node *original = head;
        Node *clone = cloneHead;
        while (original && clone)
        {
            mapping[original] = clone;
            original = original->next;
            clone = clone->next;
        }
        original = head;
        clone = cloneHead;
        while (original)
        {
            clone->random = mapping[original->random];
            original = original->next;
            clone = clone->next;
        }
        return cloneHead;
    }
};