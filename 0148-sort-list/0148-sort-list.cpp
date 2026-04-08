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
// class Solution {
// public:
//     // ListNode* sortList(ListNode* head) {
//     //     if(head == nullptr || head->next == nullptr) return head;

//     //     ListNode* temp = head;
//     //     vector<int> arr;
//     //     while(temp != nullptr){
//     //         arr.push_back(temp->val);
//     //         temp = temp->next;
//     //     }
//     //     sort(arr.begin(),arr.end(),greater<int>());
//     //     temp = head;
//     //     while(!arr.empty()){
//     //         temp->val = arr.back();
//     //         arr.pop_back();
//     //         temp = temp->next;
//     //     }
//     //     return head;
//     // }


// };

class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val){
            l1->next = merge(l1->next ,l2);
            return l1;
        }else{
            l2->next = merge(l1,l2->next);
            return l2;
        }
        return nullptr;
    }
    ListNode* getMid(ListNode* head){
        if(head == nullptr || head ->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* sortList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = getMid(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        // sort both halfs
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        //merge 
        return merge(left,right);

    }
    
};