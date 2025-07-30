// LeetCode 61
// Given the head of a linked list, rotate the list to the right by k places.

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }
        int len = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        k = k % len;
        if (k == 0)
            return head;
        tail->next = head;
        tail = tail->next;
        for (int i = 0; i < len - k - 1; i++)
        {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};