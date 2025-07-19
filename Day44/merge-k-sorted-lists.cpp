// LeetCode 23
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

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
private:
    ListNode *mergeList(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                curr->next = list2;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }

        if (list1 != NULL)
            curr->next = list1;
        else if (list2 != NULL)
            curr->next = list2;

        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;

        while (lists.size() > 1)
        {
            vector<ListNode *> mergedLists;
            for (int i = 0; i < lists.size(); i += 2)
            {
                ListNode *l1 = lists[i];
                ListNode *l2 = (i + 1) < lists.size() ? lists[i + 1] : NULL;
                mergedLists.push_back(mergeList(l1, l2));
            }
            lists = mergedLists;
        }

        return lists[0];
    }
};