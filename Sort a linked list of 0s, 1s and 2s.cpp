class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head == NULL) return head;
        priority_queue<int, vector<int>, greater<int>> mp;
        
        Node* curr = head;
        
        while(curr){
            mp.push(curr->data);
            curr = curr->next;
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while(!mp.empty()){
            tail->next = new Node(mp.top());
            mp.pop();
            tail = tail->next;
        }
        
        return dummy->next;
    }
};
