// LeetCode 725
// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
// Return an array of the k parts.

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k, NULL);
        int size = 0;
        ListNode *dummy = head;
        while (dummy)
        {
            size++;
            dummy = dummy->next;
        }
        int n = size / k, r = size % k;
        dummy = head;
        for (int i = 0; i < k; i++)
        {
            ans[i] = dummy;
            for (int j = 0; j < n - 1 + (r > 0); j++)
            {
                if (dummy == NULL)
                    break;
                dummy = dummy->next;
            }
            if (dummy)
            {
                ListNode *temp = dummy->next;
                dummy->next = NULL;
                dummy = temp;
            }
            r--;
        }
        return ans;
    }
};