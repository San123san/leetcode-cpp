class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_set<int> s;
        
        while(head2 != NULL){
            s.insert(head2->data);
            head2 = head2->next;
        }
        
        Node* res = new Node(0);
        Node* temp = res;
        
        while(head1 != NULL){
            if(s.find(head1->data) != s.end()){
                temp->next = new Node(head1->data);
                temp = temp->next;
            }
            head1 = head1->next;
        }
        return res->next;
    }
};
