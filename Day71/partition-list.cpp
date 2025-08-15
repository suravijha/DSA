// LeetCode 86
// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *l1 = new ListNode(0, NULL);
        ListNode *l2 = new ListNode(0, NULL);
        ListNode *small = l1;
        ListNode *big = l2;

        while (head)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }

        small->next = l2->next;
        big->next = NULL;

        ListNode *ans = l1->next;
        delete l1;
        delete l2;
        return ans;
    }
};