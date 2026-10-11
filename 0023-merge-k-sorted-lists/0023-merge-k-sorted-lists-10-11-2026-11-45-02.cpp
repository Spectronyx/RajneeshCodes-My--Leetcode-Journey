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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using pq;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto list: lists){
            while(list){
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode* ans = new ListNode(0);
        ListNode* head = ans;

        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            
            ListNode* newNode = new ListNode(top);
            ans->next = newNode;
            ans = ans->next;
        }

        return head->next;
    }
};