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
    // ListNode* middleNode(ListNode* head) {
    //     int count = 0;

    //     if(head == nullptr || head->next == nullptr) return head;

    //     ListNode *temp = head;
    //     while(temp != nullptr){
    //         temp = temp->next;
    //         count++;
    //     }

    //     int mid = count/2+1;

    //     temp = head;

    //     while(temp != nullptr){
    //         mid = mid-1;

    //         if(mid == 0) break;

    //         temp = temp->next;
    //     }

    //     return temp;
    // }

        ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;

            fast = fast->next->next;

        } 
        return slow;
    }
};