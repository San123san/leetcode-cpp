/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> res;
        
        Node* curr = root;
        
        while (curr != NULL || !q.empty()) {
            if (curr == NULL) {
                curr = q.front();
                q.pop();
            }
            
            while (curr != NULL) {
                res.push_back(curr->data);
                if (curr->left) {
                    q.push(curr->left);
                }
                curr = curr->right;
            }
        }
        return res;
    }
};
