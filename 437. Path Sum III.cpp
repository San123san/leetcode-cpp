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
    void pathS(TreeNode* root, int targetSum, long long sum, int& path) {
        if (root == NULL) return;

        sum += root->val;

        if (sum == targetSum) {
            path++;
        }

        pathS(root->left, targetSum, sum, path);
        pathS(root->right, targetSum, sum, path);
    }
    void dfs(TreeNode* root, int targetSum, int& path) {
        if (root == NULL) return;

        pathS(root, targetSum, 0, path);

        dfs(root->left, targetSum, path);
        dfs(root->right, targetSum, path);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int path = 0;
        dfs(root, targetSum, path);
        return path;
    }
};
