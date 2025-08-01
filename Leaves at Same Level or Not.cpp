/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    int maxDis(Node* curr) {
        if (curr == NULL) return 0;
        
        int left_dis = maxDis(curr->left);
        int right_dis = maxDis(curr->right);
        
        return  1 + max(left_dis, right_dis);
    }
    int minDis(Node* curr) {
        if (curr == NULL) return INT_MAX;
        
        if (curr->left == NULL && curr->right == NULL) {
            return 1;
        }
        
        int left_dis = minDis(curr->left);
        int right_dis = minDis(curr->right);
        
        return 1 + min(left_dis, right_dis);
    }
    /*You are required to complete this method*/
    bool check(Node *root) {
        // Your code here
        if (root == NULL) return true;
        
        int max_dis = maxDis(root);
        int min_dis = minDis(root);
        
        if (max_dis == min_dis) return true;
        
        return false;
    }
};
