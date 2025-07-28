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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> res;
        
        if (root == NULL) return res;
        
        map<int, int> topNode;
        
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();
            
            Node* curr = front.first;
            int hd = front.second;
            
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = curr->data;
            }
            if (curr->left) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }
        
        for (auto it = topNode.begin(); it != topNode.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
