class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        st = temp;
    }
};
