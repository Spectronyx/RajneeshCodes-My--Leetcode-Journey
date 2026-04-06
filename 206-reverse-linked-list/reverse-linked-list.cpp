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
    // using stack
    // ListNode* reverseList(ListNode* head) {

    //     ListNode* temp = head;
    //     stack<int> st;


    //     while(temp != nullptr){
    //         st.push(temp->val);
    //         temp = temp->next;
    //     }

    //     temp = head;

    //     while(!st.empty()){
    //         temp->val = st.top();
    //         st.pop();
    //         temp = temp->next;
    //     }
        
    //     return head;
    // }
    // using iterative method;
    // ListNode* reverseList(ListNode* head) {

    //     // iterative apporach
    //     ListNode *prev = nullptr;

    //     ListNode *temp = head;

    //     while(temp != nullptr){
    //         ListNode* front = temp->next;

    //         temp->next = prev;

    //         prev = temp;

    //         temp = front;
    //     }
    //         return prev;
    // }

    // using recursion
    ListNode* reverseList(ListNode* head){
        // base case if the list has one only one node or no node
        if(head == nullptr || head->next == nullptr) return head;

        // recursively reverse the list
        ListNode* newHead = reverseList(head->next);

        // store the next node
        ListNode *front = head->next;

        // make the next node point to current node;

        front->next = head;

        // break the current node forward linked
        head->next = nullptr;
        return newHead;
    }



};