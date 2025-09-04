/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void Inorder(Node* root, vector<int>& res) {
    if (root == nullptr) return;
    Inorder(root->left, res);
    res.push_back(root->data);
    Inorder(root->right, res);
}
    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> r1, r2;
        
        Inorder(root1, r1);
        Inorder(root2, r2);
        
        int i = 0, j = r2.size()-1;
        int count = 0;
        
        while (i < r1.size() && j >= 0) {
            int sum = r1[i] + r2[j];
            
            if (sum == x) {
                count++;
                i++;
                j--;
            } else if (sum < x) {
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
};
