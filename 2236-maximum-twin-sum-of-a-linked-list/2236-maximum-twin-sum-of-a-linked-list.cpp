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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
       ListNode* fast = head;
       ListNode* slow = head;

       while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
       } 

       ListNode* firstHalf = head;
       ListNode* secondHalf = reverseList(slow);

        int ans = INT_MIN;
       while(secondHalf){
            ans = max(ans,secondHalf->val+firstHalf->val);
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
       }

       return ans;
    }

    //solution1
    // int pairSum(ListNode* head) {
    //     vector<int> arr;

    //     ListNode* temp = head;
    //     while(temp != NULL){
    //         arr.push_back(temp->val);
    //         temp = temp->next;
    //     }
    //     int n = arr.size();
    //     int ans = INT_MIN;
    //     for(int i = 0;i <=n/2;i++){
    //         int sum = arr[i]+ arr[n-i-1];
    //         ans = max(ans,sum);
    //     }
    //     return ans;
    // }
};