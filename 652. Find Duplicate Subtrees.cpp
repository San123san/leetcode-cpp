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
    string getSub(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& res) {
        if (root == NULL) {
            return "N";
        }

        string s = to_string(root->val) + "," + getSub(root->left, mp, res) + "," + getSub(root->right, mp, res);

        if (mp[s] == 1) {
            res.push_back(root);
        }

        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> res;

        getSub(root, mp, res);

        return res;
    }
};
