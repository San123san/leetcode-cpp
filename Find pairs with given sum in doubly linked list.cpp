class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>> res;
        
        Node* left = head;
        Node* right = head;
        
        if (!head || !head->next) return res;
        
        while(right->next){
            right = right->next;
        }
        
        while(left != right && left->prev != right){
            int sum = left->data + right->data;
            
            if(sum == target){
                res.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if (sum < target) {
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        return res;
    }
};
