/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        curr = head;
        
        int carry = 1;
        Node* temp = NULL;

        while (curr != NULL) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            temp = curr;
            curr = curr->next;
        }

        if (carry > 0) {
            temp->next = new Node(carry);
        }
        
        curr = head;
        prev = NULL;
        next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        // return head of list after adding one
    }
};
