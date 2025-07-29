/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leaf(Node* root, vector<int>& res) {
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->data);
            return;
        }
        
        leaf(root->left, res);
        leaf(root->right, res);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        
        if (root == NULL) return res;
        
        if (root->left || root->right) {
            res.push_back(root->data);
        }
        
        Node* curr = root->left;
        while (curr) {
            if (curr->left || curr->right) {
                res.push_back(curr->data);
            }
            if (curr->left) {
                curr = curr->left;
            } else if (curr->right) {
                curr = curr->right;
            } else {
                break;
            }
        }
        
        leaf(root, res);
        
        stack<int> s;
        curr = root->right;
        while (curr) {
            if (curr->left || curr->right) {
                s.push(curr->data);
            }
            if (curr->right) {
                curr = curr->right;
            } else if (curr->left) {
                curr = curr->left;
            } else {
                break;
            }
        }
        
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};
