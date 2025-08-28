/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    void inorder(Node* root, Node*& prev) {
        if (!root) return;
        inorder(root->left, prev);
        if(prev) prev->next = root;
        prev = root;
        inorder(root->right, prev);
    }
    void populateNext(Node *root) {
        // code here
        Node* prev = nullptr;
        inorder(root, prev);
    }
};
