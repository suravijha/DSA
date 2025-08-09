// LeetCode 707
// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.

class MyLinkedList
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x)
        {
            val = x;
            next = NULL;
        }
    };

public:
    ListNode *head;
    int size;
    MyLinkedList()
    {
        head = new ListNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (index >= size)
        {
            return -1;
        }
        ListNode *node = head->next;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val)
    {
        ListNode *first = new ListNode(val);
        first->next = head->next;
        head->next = first;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *node = head;
        ListNode *last = new ListNode(val);
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = last;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        ListNode *add = new ListNode(val);
        ListNode *node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        add->next = node->next;
        node->next = add;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        ListNode *node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        ListNode *temp = node->next;
        node->next = node->next->next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */