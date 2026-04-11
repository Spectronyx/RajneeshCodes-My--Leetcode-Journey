/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // approach one 
        // map
        unordered_map<Node*,Node*> mp;
        Node* curr = head;
        Node* prev = nullptr;
        Node* newHead = nullptr;

        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            if(newHead == nullptr){
                newHead = newNode;
                prev = newHead;
            }else{
                prev->next = newNode;
                prev        =newNode;
            }
            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;
        while(curr){
            if(curr->random == nullptr){
                newCurr->random = nullptr;
            }else{
                newCurr->random = mp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;

        }

        return newHead;
    }
};