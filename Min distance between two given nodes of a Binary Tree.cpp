/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* findLCA(Node* root, int a, int b) {
        if (root == NULL) return NULL;
        if (root->data == a || root->data == b) return root;
        
        Node* leftLCA = findLCA(root->left, a, b);
        Node* rightLCA = findLCA(root->right, a, b);
        
        if (leftLCA && rightLCA) return root;
        
        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }
    
    int findDis(Node* root, int target, int dist) {
        if (root == NULL) return -1;
        
        if (root->data == target) return dist;
        
        int leftDist = findDis(root->left, target, dist + 1);
        if (leftDist != -1) return leftDist;
        
        return findDis(root->right, target, dist + 1);
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca = findLCA(root, a, b);
        
        int distA = findDis(lca, a, 0);
        int distB = findDis(lca, b, 0);
        
        return distA + distB;
    }
};
