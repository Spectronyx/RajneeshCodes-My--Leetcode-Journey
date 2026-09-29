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
    // ListNode* reverseList(ListNode* head) {
    //     if(!head) return head;

    //     ListNode* current = head;
    //     ListNode* prev = nullptr;

    //     while(current != nullptr){
    //         ListNode* next = current->next;

    //         current->next = prev;

    //         prev = current;
    //         current = next;
    //     }
    //     return prev;
    // }

    ListNode* reverseList(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;

        head->next = nullptr;

        return newHead;
    }
};