// User function Template for C++

class Solution {
  public:
    // Function to find largest subtree sum.
    int largest(Node* root, int& maxSum) {
        if (root == NULL) return 0;
        
        int lt = largest(root->left, maxSum);
        int rt = largest(root->right, maxSum);
        
        maxSum = max(maxSum, lt + rt + root->data);
        
        return lt + rt + root->data;
    }
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        if (root == NULL) return 0;
        int maxSum = INT_MIN;
        largest(root, maxSum);
        return maxSum;
    }
};
