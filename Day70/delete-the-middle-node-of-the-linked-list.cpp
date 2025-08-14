// LeetCode 2095
// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

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
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* dummy = new ListNode(-1, head);
        while(fast && fast -> next){
            dummy = dummy -> next;
            fast = fast -> next -> next;
        }
        dummy -> next = dummy -> next -> next;
        return head;
    }
};