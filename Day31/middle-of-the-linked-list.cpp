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
    int getLength(ListNode *head)
    {
        ListNode *temp = head;
        int ans = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            ans++;
        }
        return ans;
    }

public:
    ListNode *middleNode(ListNode *head)
    {
        int index = getLength(head) / 2;
        ListNode *ans = head;
        for (int i = 0; i < index; i++)
        {
            ans = ans->next;
        }
        return ans;
    }
};