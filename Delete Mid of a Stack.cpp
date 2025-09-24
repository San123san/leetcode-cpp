class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMidH(stack<int>& s, int curr, int mid){
        if (curr == mid) {
            s.pop();
            return;
        }
        
        int temp = s.top();
        s.pop();
        deleteMidH(s, curr + 1, mid);
        s.push(temp);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        if (s.empty()) return;
        
        int size = s.size();
        int midB = (size + 1) / 2;
        int midT = size - midB + 1;
        
        deleteMidH(s, 1, midT);
    }
};
