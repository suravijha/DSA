// LeetCode 143
// You are given the head of a singly linked-list. The list can be represented as: L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form: L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == NULL)
            return;
        vector<ListNode *> nodes;
        ListNode *cur = head;
        while (cur)
        {
            nodes.push_back(cur);
            cur = cur->next;
        }
        int i = 0;
        int j = nodes.size() - 1;
        while (i < j)
        {
            nodes[i]->next = nodes[j];
            i++;
            if (i >= j)
                break;
            nodes[j]->next = nodes[i];
            j--;
        }
        nodes[i]->next = NULL;
    }
};