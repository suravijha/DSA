// LeetCode 203
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return head;
        while (head != NULL && head->val == val)
            head = head->next;
        ListNode *temp = head;
        while (temp && temp->next)
        {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};