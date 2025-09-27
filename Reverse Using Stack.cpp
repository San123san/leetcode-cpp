class Solution {
  public:
    string reverse(const string& S) {
        // code here
        stack<char> s;
        string rev = "";
        
        for (char c : S) {
            s.push(c);
        }
        
        while (!s.empty()) {
            rev += s.top();
            s.pop();
        }
        
        return rev;
    }
};
