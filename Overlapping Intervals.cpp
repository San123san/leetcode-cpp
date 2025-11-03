class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end()); 
    stack<vector<int>> st;
    st.push(arr[0]); 

    for(int i = 1; i < arr.size(); ++i) {
        if(st.top()[1] >= arr[i][0]) {
            st.top()[1] = max(st.top()[1], arr[i][1]);
        } else {
            st.push(arr[i]);
        }
    }

    vector<vector<int>> res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
    }
};
