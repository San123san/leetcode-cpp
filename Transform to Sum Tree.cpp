/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  int toSumTree(Node* node) {
        if (node == NULL) return 0;

        int leftSum = toSumTree(node->left);

        int rightSum = toSumTree(node->right);
        
        int temp = node->data;
        node->data = leftSum + rightSum;

        return temp + node->data;
    }

    void convertToSumTree(Node* root) {
        toSumTree(root);
    }
};
