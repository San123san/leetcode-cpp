class Solution {
  public:
    Node* getTail(Node* curr){
        while(curr != NULL && curr->next != NULL){
            curr = curr->next;
        }
        return curr;
    }
    
    Node* partition(Node* head, Node* tail){
        Node* pivot = head;
        
        Node* pre = head;
        Node* curr = head;
        
        while(curr != tail->next){
            if(curr->data < pivot->data){
                pre = pre->next;
                swap(curr->data, pre->data);
            }
            curr = curr->next;
        }
        swap(pivot->data, pre->data);
        return pre;
    }
    
    void quickSortHelper(Node* head, Node* tail){
        
        if(head == NULL || head == tail || head == tail->next){
            return;
        }
        
        Node* pivot = partition(head, tail);
        
        quickSortHelper(head, pivot);
        quickSortHelper(pivot->next, tail);
    }
    
    struct Node* quickSort(struct Node* head) {
        // code here
        Node* tail = getTail(head);
        
        quickSortHelper(head, tail);
        return head;
    }
};
