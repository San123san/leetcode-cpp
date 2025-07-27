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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return {};

        stack<TreeNode*> s;
        vector<int> res;
        s.push(root);
        stack<int> out;

        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            out.push(curr->val);

            if (curr->left) {
                s.push(curr->left);
            }
            if (curr->right) {
                s.push(curr->right);
            }
        }

        while (!out.empty()) {
            res.push_back(out.top());
            out.pop();
        }
        return res;
    }
};
