class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        Node* first = head;

        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        head->next = prev;
        head = prev;

        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        
        // code here
        if(head == NULL) return head;
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr->data != key){
            if(curr->next == head){
                return head;
            }
            prev = curr;
            curr = curr->next;
        }
        
        if(curr == head && curr->next == head){
            head = NULL;
            return head;
        }
        
        if(curr == head){
            prev = head;
            while(prev->next != head){
                prev = prev->next;
            }
            head = curr->next;
            prev->next = head;
        }
        
        else if(curr->next == head){
            prev->next = head;
        }
        
        else{
            prev->next = curr->next;
        }
        
        return head;
        
    }
};
