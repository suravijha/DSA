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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};

        int mini = INT_MAX;

        ListNode* prev = head;
        ListNode* cur = head -> next;
        int index = 1;
        int prevCritical = 0;
        int firstCritical = 0;

        while (cur -> next != nullptr) {
            if ((cur -> val < prev -> val && cur -> val < cur -> next -> val) ||
            ((cur -> val > prev -> val && cur -> val > cur -> next -> val))) {
                if (prevCritical == 0) {
                    prevCritical = index;
                    firstCritical = index;
                } else {
                    mini = min(mini, index - prevCritical);
                    prevCritical = index;
                }
            }

            index++;
            prev = cur;
            cur = cur -> next;
        }

        if (mini != INT_MAX) {
            int maxi = prevCritical - firstCritical;
            result = {mini, maxi};
        }

        return result;
    }
};