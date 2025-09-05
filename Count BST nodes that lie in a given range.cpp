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
    void solve(Node* root, int l, int h, int& ans) {
        if (!root) return NULL;
        
        if (root->data > l && root->data < h) {
            ans++;
        }
        
        else if (root->data < l)
            solve(root->right, l, h, ans);


        else 
            solve(root->left, l, h, ans);
    }
    int getCount(Node *root, int l, int h) {
        // your code here
        int ans = 0;
        solve(root, l, h, ans);
        return ans;
    }
};
