// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> res(n, 1);
        
        int pre = 1;
        for (int i = 0; i < n; i++) {
            res[i] = pre;
            pre *= arr[i];
        }
        
        int suf = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suf;
            suf *= arr[i];
        }
        
        return res;
    }
};
