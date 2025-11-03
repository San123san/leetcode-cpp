class Solution {
  public:
    void insertSort(stack<int> &st, int ele) {
        if (st.empty() || st.top() <= ele) {
            st.push(ele);
            return;
        }
        
        int temp = st.top();
        st.pop();
        insertSort(st, ele);
        
        st.push(temp);
    }
    void sortStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
        
        int topEle = st.top();
        st.pop();
        
        sortStack(st);
        
        insertSort(st, topEle);
    }
};
