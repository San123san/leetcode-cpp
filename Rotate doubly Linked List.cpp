class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

        // code here..
        if(!head || p == 0) return head;
        Node* temp = head;
        int length = 1;
        while(temp->next != NULL) {
            temp = temp->next;
            length++;
        }
        
        p = p % length;
        if(p == 0) return head;
        
        temp->next = head;
        head->prev = temp;
        temp = head;
        for(int i = 1; i < p; i++){
            temp = temp->next;
        }
        
        Node* newHead = temp->next;
        temp->next = NULL;
        newHead->prev = NULL;
        
        return newHead;
    }
};
