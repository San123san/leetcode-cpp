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
        if(head == NULL) return head;

        unordered_map<Node*, Node*> mp;
        Node* dummy = new Node(0);
        Node* deepCopy = dummy;
        
        Node* curr = head;
        while(curr != NULL){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL){
            deepCopy->next = mp[curr];               
            mp[curr]->next = mp[curr->next];         
            mp[curr]->random = mp[curr->random];    
            deepCopy = deepCopy->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};
