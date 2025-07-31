// LeetCode 82
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

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
        {
            return head;
        }
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                int duplicate = head->val;
                while (head && head->val == duplicate)
                {
                    head = head->next;
                }
                prev->next = head;
            }
            else
            {
                prev = head;
                head = head->next;
            }
        }
        return dummy->next;
    }
};