// User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int, stack<int>> mp;
        
        for (int i = 0; i < e; i++) {
            mp[A[2*i]].push(A[2*i+1]);
        }
        
        for (int i = 0; i < e; i++) {
            if (mp[B[2*i]].top() != B[2*i+1]) {
                return 0;
            }
            mp[B[2*i]].pop();
        }
        return 1;
    }
};
