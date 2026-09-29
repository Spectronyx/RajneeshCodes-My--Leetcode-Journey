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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val<l2->val){
            l1->next = merge(l1->next,l2);
            return l1;
        }else{
            l2->next = merge(l1,l2->next);
            return l2;
        }
        return nullptr;
    }

    ListNode* getMid(ListNode* head){
        if(head == nullptr) return head;

        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = getMid(head);
        
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left,right);
    
    }
};