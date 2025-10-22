class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
         int n = mat.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            st.push(i);
        }
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (mat[a][b] == 1) {
                st.push(b);
            } else {
                st.push(a);
            }
        }
        int c = st.top();
        for (int i = 0; i < n; i++) {
            if (i == c) continue;
            if (mat[c][i] == 1 || mat[i][c] == 0)
                return -1;
        }
        return c;
    }
};
