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
    // ListNode* removeNthNode(ListNode* head , int n){
    //     if(n == 0){
    //         ListNode* temp = head;
    //         head = head->next;
    //         delete temp;
    //         return head;
    //     }
    //     ListNode* temp = head;
    //     for(int i = 0;i<n-1 && temp != nullptr;i++){
    //         temp = temp->next;
    //     }
    //     if(temp == nullptr || temp->next == nullptr){
    //         return head;
    //     }
    //     // deletion node
    //     ListNode *delNode = temp->next;
    //     temp->next = temp->next->next;
    //     delete delNode;
    //     return head;
    // }
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     // list reverse karke nth node from start remove ka do 
    //     // ya fir head pointer to last me lekar jao aur last se nth node remove kar do
    //     // brute force calculate the length and remove the l-nth node from first

    //     int count = 0;
    //     ListNode* temp = head;
    //     while(temp != nullptr){
    //         count++;
    //         temp = temp->next;
    //     }

    //     return removeNthNode(head,count-n);

    // }

    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* fast = head;
        ListNode* slow = head;

        // move fast n step ahead;
        for(int i = 0;i < n;i++){
            fast = fast->next;
        }
        // if fast is null remvoe the head;
        if(fast == nullptr){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};