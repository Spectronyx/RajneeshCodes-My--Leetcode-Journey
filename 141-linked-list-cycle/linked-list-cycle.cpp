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
    // bool hasCycle(ListNode *head) {
    //     // bruteforce apporach
    //     ListNode* temp = head;

    //     unordered_map<ListNode*,int> mp;

    //     while(temp != nullptr){
    //         if(mp.find(temp) != mp.end()){
    //             return true;
    //         }

    //         // store in unordered_map
    //         mp[temp] = 1;
    //         temp = temp->next;
    //     }
    //     return false;
    // }
    bool hasCycle(ListNode *head) {
        // better approach using turle and hare
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!= nullptr && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};