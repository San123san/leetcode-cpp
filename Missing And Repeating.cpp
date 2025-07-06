class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<bool> visited(n + 1, false);
        int repeat = -1;
        int missing = -1;
        
        for (int i = 0; i < n; i++) {
            if (visited[arr[i]]) {
                repeat = arr[i];
            } else {
                visited[arr[i]] = true;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                missing = i;
                break;
            }
        }
        
        return {repeat, missing};
    }
};
