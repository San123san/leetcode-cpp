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
    TreeNode* solve(vector<int>& preorder, int min, int max, int& i) {
        if (i >= preorder.size()) return NULL;

        if (preorder[i] < min || preorder[i] > max) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, min, root->val, i);
        root->right = solve(preorder, root->val, max, i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN;
        int max = INT_MAX;
        int i = 0;
        return solve(preorder, min, max, i);
    }
};
