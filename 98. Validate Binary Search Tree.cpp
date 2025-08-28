/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBST(TreeNode* root, long long min, long long max) {
        if (!root) return true;

        if (root->val > min && root->val < max) {
            bool left = isBST(root->left, min, root->val);
            bool right = isBST(root->right, root->val, max);
            return left && right;
        } else {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        int min = INT_MIN;
        int max = INT_MAX;
        return isBST(root,LONG_MIN, LONG_MAX);
    }
};
