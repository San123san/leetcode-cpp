/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> res;
        
        if (root == NULL) return res;
        
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 1; i <= n; i++) {
                Node* curr = q.front();
                q.pop();
                
                if (i == 1) {
                    res.push_back(curr->data);
                }
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};
