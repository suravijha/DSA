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
class Solution {
private:
    int getLength(ListNode* head){
        int count = 0;
        while (head != NULL) {
            count++;
            head = head -> next;
        }
        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;

        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;

        int count = 0;

        while (curr != NULL && count < k) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if (forward != NULL && getLength(forward) >= k)
            head -> next = reverseKGroup(forward, k);
        else
            head -> next = forward;

        return prev;
    }
};