// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> maxSum(Node* root) {
        if (root == NULL) {
            pair<int, int> sum(0, 0);
            return sum;
        }
        
        pair<int, int> sum1 = maxSum(root->left);
        pair<int, int> sum2 = maxSum(root->right);
        
        pair<int, int> sum;
        
        sum.first = sum1.second + sum2.second + root->data;
        sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);
        
        return sum;
    }
    int getMaxSum(Node *root) {
        // code here
        pair<int, int> res = maxSum(root);
        return max(res.first, res.second);
    }
};
