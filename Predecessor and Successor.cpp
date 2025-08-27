/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = nullptr;
        Node* suc = nullptr;
        Node* current = root;
        while (current) {
            if (current->data == key) {
                // If left subtree exists, predecessor is the max value in left subtree
                if (current->left) {
                    Node* temp = current->left;
                    while (temp->right) temp = temp->right;
                    pre = temp;
                }

                if (current->right) {
                    Node* temp = current->right;
                    while (temp->left) temp = temp->left;
                    suc = temp;
                }
                break;
            } else if (current->data > key) {
                suc = current;
                current = current->left;
            } else {
                pre = current;
                current = current->right;
            }
        }

        return {pre, suc};
    }
};

