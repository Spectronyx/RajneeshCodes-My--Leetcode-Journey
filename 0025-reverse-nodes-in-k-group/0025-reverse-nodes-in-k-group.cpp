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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        // check if k nodes exists
        for(int i =0 ;i< k;i++){
            if(temp == nullptr) return head;
            temp = temp->next;
        }

        // reverse the k nodes 
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0 ;i< k;i++){
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }

        // call the recursive 
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};