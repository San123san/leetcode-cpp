class Compare {
    public:
         bool operator()(DLLNode* a, DLLNode* b){
             return a->data > b->data;
         }
};
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        if(head == NULL) return head;
        
        priority_queue<DLLNode*, vector<DLLNode*>, Compare> pq;
        
        DLLNode* newHead = NULL, *last = NULL;
        
        for(int i = 0; head != NULL && i < k + 1; i++){
            pq.push(head);
            head = head->next;
        }
        
        while (!pq.empty()){
            if(newHead == NULL){
                newHead = pq.top();
                newHead->prev = NULL;
                last = newHead;
            } else {
                last->next = pq.top();
                pq.top()->prev = last;
                last = pq.top();
            }
            pq.pop();
            
            if(head != NULL){
                pq.push(head);
                head = head->next;
            }
        }
        
        last->next = NULL;
        return newHead;
    }
};
