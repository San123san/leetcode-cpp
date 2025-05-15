class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next != head && fast->next->next != head){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* head1 = head;
        Node* head2 = slow->next;
        Node* temp2 = head2;
        while(temp2->next != head){
            temp2 = temp2->next;
        }
        temp2->next = slow->next;
        
        Node* temp1 = head1;
        while(temp1 != slow){
            temp1 = temp1->next;
        }
        temp1->next = head1;
        
        
        return {head1, head2};
    }
};
