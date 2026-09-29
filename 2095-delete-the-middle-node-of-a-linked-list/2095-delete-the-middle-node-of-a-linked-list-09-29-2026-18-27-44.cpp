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

        // Only one node
        if (head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast->next != nullptr && fast->next->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now before the middle
        ListNode* temp = slow->next;

        slow->next = slow->next->next;

        delete temp;

        return head;
    }
};