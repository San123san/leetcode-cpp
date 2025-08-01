/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    int isSum(Node* root) {
        if (root == NULL) return 0;
        
        if (root->left == NULL && root->right == NULL) {
            return root->data;
        }
        
        int ls = isSum(root->left);
        
        if (ls == -1) return -1;
        
        int rs = isSum(root->right);
        
        if (rs == -1) return -1;
        
        if (ls + rs == root->data) {
            return ls + rs + root->data;
        } else {
            return -1;
        }
    }
    bool isSumTree(Node* root) {
        // Your code here
        if (isSum(root) != -1) {
            return true;
        } else {
            return false;
        }
    }
};
