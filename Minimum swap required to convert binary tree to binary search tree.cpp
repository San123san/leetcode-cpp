class Solution {
  public:
    void inorder(vector<int>& arr, vector<int>& inorderArr, int index) {

        int n = arr.size();

        // If index is out of bounds, return
        if (index >= n)
            return;

        // Recursively visit left subtree
        inorder(arr, inorderArr, 2 * index + 1);

        // Store current node value in vector
        inorderArr.push_back(arr[index]);

        // Recursively visit right subtree
        inorder(arr, inorderArr, 2 * index + 2);
    }

    // Function to calculate minimum swaps
    // to sort inorder traversal
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<int> inorderArr;

        // Get the inorder traversal of the binary tree
        inorder(arr, inorderArr, 0);

        // Create an array of pairs to store value
        // and original index
        vector<pair<int, int>> t(inorderArr.size());
        int ans = 0;

        // Store the value and its index
        for (int i = 0; i < inorderArr.size(); i++)
            t[i] = {inorderArr[i], i};

        // Sort the pair array based on values
        // to get BST order
        sort(t.begin(), t.end());

        // Find minimum swaps by detecting cycles
        for (int i = 0; i < t.size(); i++) {

            // If the element is already in the
            // correct position, continue
            if (i == t[i].second)
                continue;

            // Otherwise, perform swaps until the element
            // is in the right place
            else {

                // Swap elements to correct positions
                swap(t[i].first, t[t[i].second].first);
                swap(t[i].second, t[t[i].second].second);
            }

            // Check if the element is still not
            // in the correct position
            if (i != t[i].second)
                --i;

            // Increment swap count
            ans++;
        }

        return ans;
    }
};
