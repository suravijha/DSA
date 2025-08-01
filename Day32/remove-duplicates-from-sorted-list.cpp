// LeetCode 83
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != NULL)
        {
            if (prev->val == curr->val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};