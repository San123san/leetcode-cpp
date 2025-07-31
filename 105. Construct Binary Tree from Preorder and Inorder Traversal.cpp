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
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorder_map, int& preorderIdx, int inorderStart, int inorderEnd) {

        if (inorderStart > inorderEnd) {
            return NULL;
        }

        int rootVal = preorder[preorderIdx++];
        
        TreeNode* root = new TreeNode(rootVal);

        int inorderIdx = inorder_map[rootVal];

        root->left = build(preorder, inorder_map, preorderIdx, inorderStart, inorderIdx - 1);
        root->right = build(preorder, inorder_map, preorderIdx, inorderIdx + 1, inorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        int preorderIdx = 0;
        
        return build(preorder, inorder_map, preorderIdx, 0, inorder.size() - 1);
    }
};
