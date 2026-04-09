/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     while(headA != nullptr){
    //         ListNode* temp = headB;
    //         while(temp!= nullptr){
    //             if(temp == headA){
    //                 return headA;
    //             }
    //             temp = temp->next;
    //         }
    //         headA = headA->next;
    //     }
    //     return nullptr;
    // }

    ListNode * getIntersectionNode(ListNode* headA, ListNode* headB){
        unordered_set<ListNode*> st;
        while(headA != nullptr){
            st.insert(headA);
            headA = headA->next;
        }

        while(headB != nullptr){
            if(st.find(headB) != st.end()){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};