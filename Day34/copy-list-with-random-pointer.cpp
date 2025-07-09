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