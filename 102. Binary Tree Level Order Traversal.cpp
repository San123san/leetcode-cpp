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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> store;
        
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                res.push_back(store);
                store.clear();

                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                store.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }
        return res;

    }
};
